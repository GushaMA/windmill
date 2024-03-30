//
// Created by plutoli on 2022-05-22.
//

#include <opencv2/opencv.hpp>
#include <chrono>
#include "easy_logger.h"
#include "huaray_camera.h"
#include "classical_windmill_recognizer.h"

// 按ESC键，退出系统
// 按Enter键，暂停系统
// 按任意键，继续处理
int main(int argc, char *argv[])
{
    // 初始化日志记录器
    EasyLogger &logger = EasyLogger::GetSingleInstance();
    logger.Init();

    // 创建相机
    HuarayCamera camera;

    // 读取相机参数
    HuarayCameraParam cameraParam;
    std::string cameraYaml = "config/infantry_3/basement/huaray_camera_param.yaml";
    if (!HuarayCameraParam::LoadFromYamlFile(cameraYaml, &cameraParam))
    {
        return -1;
    }

    // 设置相机参数
    if (!camera.SetParam(cameraParam))
    {
        return -1;
    }

    // 初始化相机
    if (!camera.Init())
    {
        return -1;
    }

    // 打开相机
    if (!camera.Open())
    {
        return -1;
    }

    // 创建风车识别器
    ClassicalWindmillRecognizer recognizer;

    // 加载风车识别器参数
    ClassicalWindmillRecognizerParam recognizerParam;
    std::string recognizerYaml = "config/infantry_3/basement/classical_windmill_recognizer_param.yaml";
    if (!ClassicalWindmillRecognizerParam::LoadFromYamlFile(recognizerYaml, &recognizerParam))
    {
        return -1;
    }

    // 设置风车识别器参数
    if (!recognizer.SetParam(recognizerParam))
    {
        return -1;
    }

    // 初始化风车识别器
    if (!recognizer.Init())
    {
        return -1;
    }

    // 创建图像显示窗口
    cv::namedWindow("rawImage",cv::WINDOW_NORMAL);
    cv::resizeWindow("rawImage", 800, 600);
    cv::namedWindow("binaryImage", cv::WINDOW_NORMAL);
    cv::resizeWindow("binaryImage", 800, 600);
    cv::namedWindow("windmillObjectsImage", cv::WINDOW_NORMAL);
    cv::resizeWindow("windmillObjectsImage", 800, 600);

    // 记录初始化时间戳
    std::chrono::time_point<std::chrono::steady_clock> initTime = std::chrono::steady_clock::now();
    uint64_t initTimestamp = initTime.time_since_epoch().count();

    // 初始化数据帧索引和目标索引
    uint64_t frameIndex = 0;
    uint64_t objectIndex = 0;

    // 循环处理相机数据
    while (true)
    {
        // 记录起始时间戳
        std::chrono::time_point<std::chrono::steady_clock> beginTime = std::chrono::steady_clock::now();
        uint64_t beginTimestamp = beginTime.time_since_epoch().count();

        // 获取相机数据
        HuarayCameraData cameraData;
        camera.GetData(&cameraData);

        // 累加数据帧索引
        frameIndex++;

        // 原始图像预处理
        cv::Mat binaryImage;
        cv::Mat binaryImageobject;
        recognizer.Preprocess(cameraData.Image, &binaryImage,&binaryImageobject);

        // 检测风车Logo集合
        std::vector<ClassicalWindmillLogo> windmillLogos;
        recognizer.DetectWindmillLogos(binaryImage, cameraData.Image, &windmillLogos);

        // 检测风车扇叶集合
        std::vector<ClassicalWindmillFan> windmillFans;
        std::vector<ClassicalWindmillFan> windmillFansob;
        recognizer.DetectWindmillFans(binaryImage, &windmillFans);

        // 判断是否检测到合法的风车Logo
        bool isWindmillLogoReady = false;
        for (unsigned int i = 0; i < windmillLogos.size(); ++i)
        {
            if (windmillLogos[i].IsValid)
            {
                isWindmillLogoReady = true;
                break;
            }
        }

        // 判读是否检测到合法的风车扇叶
        bool isWindmillFanReady = false;
        for (unsigned int i = 0; i < windmillFans.size(); ++i)
        {
            if (windmillFans[i].IsValid)
            {
                isWindmillFanReady = true;
                break;
            }
        }

        // 更新目标索引
        if (isWindmillLogoReady && isWindmillFanReady)
        {
            objectIndex++;
        }

        // 计算目标检测的准确率
        float objectAccuracy = static_cast<float>(objectIndex) / static_cast<float>(frameIndex);

        // 记录截止时间戳
        std::chrono::time_point<std::chrono::steady_clock> endTime = std::chrono::steady_clock::now();
        uint64_t endTimestamp = endTime.time_since_epoch().count();

        // 输出处理结果
        std::cout << "frame index: " << frameIndex << std::endl;
        std::cout << "object index: " << objectIndex << std::endl;
        std::cout << "object accuracy: " << objectAccuracy << std::endl;
        std::cout << "fps: " << (frameIndex * 1000000000) / (endTimestamp - initTimestamp) << std::endl;
        std::cout << "process time: " << (endTimestamp - beginTimestamp) / 1000000 << "ms" << std::endl;
        std::cout << "**************************************************" << std::endl << std::endl;

        // 创建风车目标图像
        cv::Mat windmillObjectsImage;
        ClassicalWindmillRecognizer::CreateWindmillObjectsImage(windmillLogos,
                                                                windmillFans,
                                                                cameraData.Image,
                                                                &windmillObjectsImage);

        // 显示图像
        cv::imshow("rawImage", cameraData.Image);
        cv::imshow("binaryImage", binaryImage);
        cv::imshow("windmillObjectsImage", windmillObjectsImage);

        // 读取按键的ASCII码；注意：cv::waitKey()返回的是按键的ASCII码
        int keyValue = cv::waitKey(10);

        // 如果按下ESC键，退出系统
        if (keyValue == 27)
        {
            break;
        }

        // 如果按下Enter键，暂停系统
        if (keyValue == 13)
        {
            cv::waitKey(0);
        }
    }

    // 关闭相机
    camera.Close();

    // 释放相机资源
    camera.Release();

    // 释放风车识别器资源
    recognizer.Release();

    return 0;
}