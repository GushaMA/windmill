//
// Created by gusha on 23-10-31.
//
//
// Created by gusha on 23-10-28.
//

//#include <opencv2/opencv.hpp>
//#include <chrono>
//#include "easy_logger.h"
//#include "huaray_camera.h"
//#include "classical_windmill_recognizer.h"
//#include "solver.h"
//
//using namespace std;
//
//uint64_t temp1,temp2;
//int times = 1e3;
//
//
//void fun (){
//
//    std::chrono::time_point<std::chrono::steady_clock> funbegainTime = std::chrono::steady_clock::now();
//    uint64_t funbegainTimestamp = funbegainTime.time_since_epoch().count();
//
//   {
//        sleep(5);
//        std::chrono::time_point<std::chrono::steady_clock> funTime = std::chrono::steady_clock::now();
//        uint64_t funTimestamp = funTime.time_since_epoch().count();
//
//        temp1 = funTimestamp - funbegainTimestamp ;
//
//    }
//
//}
//
//void Timefun (){
//
//    std::chrono::time_point<std::chrono::steady_clock> b_video_timePoint = std::chrono::steady_clock::now();
//    uint64_t b_Videostamp = b_video_timePoint.time_since_epoch().count();
//
//    bool idex[100000];
//
//    while (1){
//
//        if ( Isvalidrun ) break;
//
//        std::chrono::time_point<std::chrono::steady_clock> e_video_timePoint = std::chrono::steady_clock::now();
//        uint64_t e_Videostamp = e_video_timePoint.time_since_epoch().count();
//
//        uint64_t temp_times = (e_Videostamp - b_Videostamp) / 10000000;
//
//        if ( !idex[temp_times] )  {
//            video >> cameraData.Image;
//            idex[temp_times] = true;
//        }
//
//    }
//
//
//}

//#include "ceres/ceres.h"
//#include "classcal_windmill_cerese_predictor.h"
//#include "glog/logging.h"
//#include<iostream>
//#include<thread>
//#include<string>

#include <iostream>
#include <vector>


float time_datas[2000] = {

        0.0228971,0.0450677,0.0649736,0.0858832,0.121731,0.142107,0.16193,0.182377,0.202553,0.222695,0.242469,0.262518,0.300426,0.320072,0.340708,0.362814,0.396888,0.447707,0.496224,
        0.547825,0.568307,0.616794,0.636539,0.702118,0.723022,0.743391,0.762905,0.781731,0.801413,0.820831,0.840077,0.85976,0.879122,0.898781,0.918954,0.93832,0.958686,0.97804,0.998097,
        1.01751,1.03777,1.05854,1.07867,1.09945,1.1194,1.13938,1.15957,1.18035,1.20098,1.22185,1.2432,1.26323,1.28486,1.30527,1.32532,1.346,1.37108,1.39706,1.42091,
        1.44213,1.46299,1.48568,1.50658,1.5282,1.54854,1.56946,1.5908,1.62823,1.68773,1.70878,1.74434,1.76487,1.78547,1.80656,1.82769,1.84855,1.86899,1.88968,1.90945,
        1.92891,1.94879,1.96959,1.9918,2.01226,2.03188,2.05159,2.07387,2.09421,2.11515,2.13715,2.15715,2.17836,2.19902,2.21987,2.24047,2.26141,2.28241,2.30273,2.32293,
        2.34254,2.37713,2.39798,2.41852,2.43893,2.45963,2.47951,2.49972,2.53944,2.56046,2.58104,2.60229,2.62376,2.64511,2.6652,2.68541,2.70627,2.72532,2.74687,2.7679,
        2.78729,2.80697,2.82657,2.84677,2.86656,2.88718,2.91218,2.9351,2.95558,2.97564,2.99532,3.01469,3.03552,3.05565,3.0761,3.09704,3.11768,3.13676,3.15687,3.17602,
        3.19611,3.21728,3.23951,3.25997,3.28048,3.30052,3.32048,3.34145,3.36178,3.38155,3.40397,3.44637,3.46683,3.48749,3.50758,3.52872,3.54996,3.56974,3.59095,3.6113,
        3.63294,3.65701,3.68071,3.70414,3.72664,3.74816,3.76931,3.79122,3.81077,3.83107,3.85152,3.87175,3.89379,3.91381,3.93447,3.95518,3.97505,3.99503,4.01577,4.03564,
        4.0554,4.07552,4.09688,4.11725,4.13727,4.15714,4.17845,4.19947,4.22078,4.24067,4.26048,4.28064,4.30212,4.32307,4.34352,4.36359,4.38454,4.40401,4.42407,4.44404,
        4.46365,4.50529,4.52626,4.54654,4.56726,4.58828,4.61015,4.63197,4.65363,4.67532,4.69739,4.71938,4.7448,4.76863,4.79375,4.81491,4.83456,4.85611,4.87698,4.89731,
        4.91925,4.95538,4.97627,4.99685,5.01755,5.03876,5.133,5.15426,5.1905,5.22701,5.24786,5.26855,5.28898,5.3093,5.32971,5.37999,5.40099,5.42195,5.44195,5.46259,
        5.4824,5.50398,5.52405,5.55958,5.58208,5.60302,5.64105,5.66201,5.68288,5.7033,5.72474,5.77094,5.79144,5.81177,5.83346,5.85369,5.8753,5.89591,5.91639,5.93822,
        5.95956,5.9817,6.00445,6.02812,6.04967,6.07109,6.09128,6.11207,6.13276,6.15352,6.17523,6.19687,6.21897,6.24041,6.26192,6.28207,6.30398,6.32459,6.34491,6.3653,
        6.38568,6.40712,6.42821,6.44844,6.46921,6.49081,6.51262,6.53433,6.55571,6.57588,6.59614,6.61581,6.63694,6.65687,6.67727,6.69772,6.72194,6.74315,6.76448,6.78526,
        6.82205,6.87286,6.99152,7.01299,7.0529,7.07537,7.09787,7.12059,7.14296,7.21536,7.23576,7.25674,7.27812,7.31559,7.36619,7.38899,7.40973,7.43097,7.46696,7.49015,
        7.51389,7.53556,7.57804,7.5998,7.62118,7.6427,7.66366,7.68757,7.70868,7.72915,7.75421,7.7767,7.79938,7.82076,7.84105,7.86287,7.88503,7.90582,7.92661,7.94728,
        7.96807,7.98906,8.00981,8.03032,8.05169,8.07406,8.09562,8.11693,8.13699,8.15783,8.18013,8.22265,8.24576,8.26569,8.28673,8.3083,8.32943,8.35243,8.37333,8.39696,
        8.42057,8.44305,8.46503,8.48851,8.51048,8.53281,8.55506,8.5749,8.59576,8.616,8.63654,8.65735,8.67876,8.69894,8.72184,8.74466,8.76814,8.78936,8.81033,8.83097,
        8.85256,8.87596,8.89641,8.91718,8.93791,8.95838,8.97908,9.00019,9.02113,9.04141,9.06195,9.08672,9.11132,9.13368,9.15468,9.17505,9.19957,9.2233,9.24483,9.26591,
        9.28719,9.3588,9.37988,9.4003,9.42403,9.44782,9.47029,9.49122,9.51857,9.54183,9.5637,9.58561,9.60689,9.62871,9.65124,9.67239,9.69386,9.71451,9.7362,9.7578,
        9.7787,9.80052,9.82259,9.8487,9.86986,9.89083,9.91206,9.93307,9.95429,9.97576,9.99671,10.0173,10.0381,10.0596,10.1342,10.1588,10.1824,10.2038,10.2258,10.2466,
        10.2681,10.2903,10.3109,10.3319,10.3538,10.3751,10.396,10.4168,10.4373,10.4584,10.4852,10.5659,10.5885,10.6132,10.6345,10.656,10.6773,10.6985,10.7201,10.7415,
        10.7635,10.7861,10.8069,10.8295,10.851,10.8715,10.8928,10.9138,10.9348,10.9569,10.9787,10.9998,11.0215,11.0436,11.0656,11.0869,11.1077,11.1287,11.1489,11.1687,
        11.1898,11.2103,11.231,11.2514,11.2719,11.2953,11.3166,11.3375,11.3583,11.3794,11.4005,11.4212,11.4432,11.4648,11.4857,11.5063,11.5285,11.5502,11.5713,11.6236,
        11.645,11.816,11.8387,11.8627,11.8857,11.908,11.9325,11.9551,11.9777,11.9993,12.0204,12.0416,12.0637,12.0862,12.1087,12.1298,12.1541,12.1757,12.1969,12.2183,
        12.2391,12.2603,12.2824,12.3047,12.327,12.3488,12.3701,12.3911,12.4153,12.4355,12.4563,12.4767,12.4979,12.519,12.5404,12.5617,12.5846,12.6073,12.6704,12.6912,
        12.712,12.7332,12.7548,12.7763,12.7986,12.8237,12.848,12.8695,12.8911,12.913,12.9331,13.0288,13.0497,13.0876,13.1088,13.1329,13.155,13.1812,13.2049,13.2273,
        13.2504,13.2725,13.2943,13.3166,13.3384,13.3618,13.3827,13.4041,13.4255,13.4486,13.4712,13.4956,13.5174,13.5385,13.5608,13.5834,13.6049,13.6259,13.6472,13.668,
        13.6888,13.7118,13.7382,13.7598,13.7811,13.8019,13.8237,13.8454,13.8661,13.8869,13.9082,13.9295,13.95,13.971,13.9914,14.0131,14.034,14.055,14.0762,14.0982,
        14.1198,14.2302,14.2516,14.2725,14.2933,14.3139,14.3351,14.3577,14.3797,14.4024,14.4249,14.4459,14.4663,14.4875,14.5092,14.53,14.5505,14.5713,14.5918,14.612,
        14.6327,14.654,14.6752,14.6966,14.717,14.7402,14.7622,14.7852,14.8067,14.8287,14.8505,14.8721,14.8945,14.9154,14.9362,14.9739,14.9956,15.0169,15.0376,15.0586,
        15.0801,15.1044,15.1268,15.2062,15.2276,15.2496,15.2706,15.2917,15.3128,15.3351,15.3571,15.4642,15.486,15.5067,15.5281,15.5502,15.572,15.5996,15.6225,15.6459,
        15.6697,15.6947,15.7172,15.7396,15.7632,15.7874,15.8126,15.8337,15.8563,15.8779,15.8987,15.9222,15.9427,15.9636,15.9855,16.0103,16.034,16.0554,16.0769,16.1003,
        16.122,16.144,16.1659,16.1877,16.2099,16.2313,16.2536,16.275,16.2965,16.3174,16.3433,16.3673,16.3894,16.4112,16.4335,16.455,16.4767,16.4979,16.5189,16.5404,
        16.5627,16.6881,16.7091,16.7332,16.7547,16.7772,16.8001,16.8228,16.8452,16.8685,16.8912,16.9135,16.9529,16.9747,16.9969,17.0191,17.0409,17.0625,17.0846,17.1059,
        17.1271,17.1484,17.171,17.1922,17.2141,17.2363,17.2587,17.2811,17.303,17.3252,17.3461,17.3678,17.3895,17.4115,17.4343,17.457,17.4789,17.5008,17.5226,17.5444,
        17.5659,17.5872,17.6089,17.6309,17.6537,17.697,17.7202,17.7413,17.763,17.7845,17.8068,17.9209,17.9421,17.9643,17.9869,18.0086,18.0303,18.0533,18.0759,18.0991,
        18.1214,18.1601,18.1819,18.2036,18.2255,18.251,18.2729,18.2943,18.3152,18.3357,18.357,18.3791,18.4011,18.4232,18.4448,18.4675,18.4891,18.5105,18.532,18.5542,
        18.577,18.601,18.6229,18.6442,18.6653,18.687,18.7089,18.7295,18.7514,18.7733,18.7951,18.8164,18.837,18.8581,18.8794,18.9031,18.9283,18.9532,18.9746,18.9959,
        19.0176,19.1359,19.158,19.1796,19.2008,19.2243,19.2482,19.272,19.2953,19.3181,19.3405,19.3626,19.3835,19.4047,19.4257,19.4466,19.469,19.4912,19.5134,19.5366,
        19.5613,19.5833,19.6407,19.6627,19.6841,19.7058,19.7274,19.749,19.774,19.7974,19.8204,19.8441,19.8655,19.8918,19.9142,19.9385,19.9621,19.9861,20.009,20.0312,
        20.0529,20.0748,20.0957,20.1173,20.1388,20.1604,20.1824,20.2043,20.2263,20.2747,20.2963,20.3391,20.3606,20.3826,20.4041,20.4258,20.4486,20.4709,20.493,20.5192,
        20.5444,20.5689,20.5929,20.6161,20.6383,20.6596,20.6813,20.7048,20.727,20.7503,20.7729,20.7952,20.8181,20.8396,20.8624,20.8859,20.9103,20.9333,20.9562,20.979,
        21.0018,21.0237,21.0449,21.0667,21.0888,21.1124,21.1346,21.158,21.1801,21.2024,21.2295,21.2536,21.2754,21.2979,21.3204,21.3419,21.3633,21.3849,21.4061,21.4272,
        21.4493,21.5789,21.6013,21.6241,21.6466,21.6707,21.6945,21.7178,21.7423,21.7653,21.7885,21.8109,21.8323,21.855,21.8955,21.9179,21.9398,21.981,22.0036,22.0266,
        22.0481,22.071,22.0966,22.1185,22.1404,22.1618,22.1868,22.2099,22.2486,22.2714,22.2939,22.317,22.3385,22.36,22.3836,22.4073,22.4299,22.4531,22.4782,22.5003,
        22.5218,22.5432,22.5651,22.5873,22.6092,22.6313,22.6542,22.6767,22.6989,22.7218,22.7456,23.0278,23.052,23.0757,23.0979,23.12,23.1418,23.1641,23.1875,23.2101,
        23.234,23.2583,23.2809,23.303,23.3259,23.3477,23.3704,23.392,23.4179,23.4409,23.4637,23.4857,23.5072,23.5287,23.5508,23.5721,23.6098,23.6329,23.6549,23.677,
        23.6991,23.7214,23.7473,23.7684,23.7929,23.8144,23.8369,23.8605,23.8826,23.9046,23.9268,23.9487,23.9708,23.9941,24.0199,24.043,24.07,24.0955,24.1179,24.1401,
        24.1626,24.3094,24.3352,24.3581,24.3811,24.4078,24.4317,24.4567,24.4804,24.5028,24.5255,24.5493,24.5732,24.5964,24.6195,24.6423,24.671,24.694,24.7205,24.7436,
        24.7701,24.7933,24.8165,24.8397,24.8629,24.8864,24.9097,24.9328,24.9543,24.976,24.9983,25.0245,25.0477,25.0706,25.0927,25.1153,25.137,25.159,25.1819,25.2047,
        25.2276,25.2502,25.2721,25.2946,25.3398,25.3627,25.3844,25.4085,25.4311,25.4535,25.4758,25.6042,25.6263,25.6495,25.6744,25.698,25.7215,25.7456,25.7686,25.7934,
        25.8169,25.8394,25.863,25.8857,25.9088,25.9306,25.9531,25.976,25.9994,26.0222,26.0449,26.0665,26.0885,26.1104,26.1322,26.1556,26.1785,26.2012,26.2242,26.2505,
        26.2729,26.2962,26.3188,26.3422,26.3649,26.3871,26.4094,26.4309,26.4538,26.477,26.4996,26.522,26.5443,26.5673,26.5895,26.6115,26.635,26.6631,26.6853,26.7083,
        26.7324,30,100,1000,1000,2000,3000,4000,5000,6000,7000,8000,9000
};

int main (){

    std::vector <float> b;
    std::vector <float> s;

    b.push_back(1);
    s.push_back(1);

    float alpha = 0.9 ,beta = 0.9;

    int m = 1;

    for ( int i = 0; i < 1112 ; i++){

        s.push_back( alpha * time_datas[i] + ( 1 - alpha) * (*(s.end() - 1) + *(b.end()) - 1) );
        b.push_back( beta * ( *(s.end() - 1) - *(s.end() - 2) )  + ( 1 - beta ) * *(b.end() -1) );
    }

    float prevalue;

    prevalue = *(s.end() - 1) + m * *(b.end() - 1 );

    std::cout << " pre =  " << prevalue << std::endl;

    return 0;

}



//void myfunc_work() {
//    cout << "myfunc_work ....." << endl;
//    // do something 5s
//    sleep(7);
//}
//
//int main() {
//    std::thread t1(myfunc_work);
//    // 阻塞当前main主线程，待子线程执行完毕后，自己恢复主线程逻辑
//    t1.join();
//    cout << "main thread ....." << endl;
//    sleep(5);
//
//}




//int main (){
//
//        Fitcoordinate::test.push_back(10);
//
//        Fitcoordinate::ttest();
//
//
//}





//using ceres::AutoDiffCostFunction;
//using ceres::CostFunction;
//using ceres::Problem;
//using ceres::Solve;
//using ceres::Solver;

// A templated cost functor that implements the residual r = 10 -
// x. The method operator() is templated so that we can then use an
// automatic differentiation wrapper around it to generate its
// derivatives.

// value =  yaw^2 + 4*yaw + 5
//double testfun (float yaw ){
//
//    return 2 * pow(yaw,2) + 4 * yaw + 5;
//}
//
//
//struct CostFunctor {
//    template <typename T>
//    bool operator()(const T* const x, T* residual) const {
//
//        double value = testfun( x[0] );
//        residual[0] = value;
//
//        std::cout << value << std::endl;
//
//        return true;
//    }
//};
//
//int main() {
//
//    double x = 0.5;
//    const double initial_x = x;
//
//    Problem problem;
//
//    CostFunction* cost_function =
//            new ceres::NumericDiffCostFunction<CostFunctor, ceres::CENTRAL, 1, 1>(new CostFunctor);
//    problem.AddResidualBlock(cost_function, nullptr, &x);
//
//    Solver::Options options;
//    options.minimizer_progress_to_stdout = true;
//    options.max_num_iterations = 15;
//    options.gradient_check_numeric_derivative_relative_step_size = 1e-1;
//    Solver::Summary summary;
//    Solve(options, &problem, &summary);
//
//    std::cout << summary.BriefReport() << "\n";
//    std::cout << " min_x : "<< x << "\n";
//    return 0;
//}


//int main (){
//
//    Eigen::Quaterniond Q_raw(cos (M_PI / 2),0,sin ( M_PI / 2 ) * 1,0);
//    Eigen::Matrix3d QMatrix = Q_raw.toRotationMatrix();
//
//    std::cout << QMatrix << std::endl;
//
//    Eigen::Vector3d euler_t = Q_raw.toRotationMatrix().eulerAngles(2,1,0);
//
//    std::cout<<" YAW: "<<euler_t(0)*57.3<<" Pitch: "<<euler_t(1)*57.3<<" Roll: "<<euler_t(2)*57.3<<std::endl;
//
//    return 0;
//}
//


//int main (){
//
//        std::thread t1(fun);
//
//        std::chrono::time_point<std::chrono::steady_clock> mainbegainTime = std::chrono::steady_clock::now();
//        uint64_t mainbegainTimestamp = mainbegainTime.time_since_epoch().count();
//
//        {
//            sleep(5);
//            std::chrono::time_point<std::chrono::steady_clock> mainTime = std::chrono::steady_clock::now();
//            uint64_t mainTimestamp = mainTime.time_since_epoch().count();
//
//            temp2 = mainTimestamp - mainbegainTimestamp ;
//
//        }
//
//    std::cout << " <------temp1----->" << temp1 << "  <-----temp2----> " << temp2 << std::endl;
//
//    return 0;
//
//}


//int main () {
//
//    ClassicalWindmillLogo temp1; temp1.ContourCenter = {560.5 , 559.5};
//    ClassicalWindmillLogo temp2; temp2.ContourCenter = {560 , 559.5};
//    ClassicalWindmillLogo temp3; temp3.ContourCenter = {1560.5 , 559};
//    ClassicalWindmillLogo temp4; temp4.ContourCenter = {560 , 559};
//    ClassicalWindmillLogo temp5; temp5.ContourCenter = {1060.5 , 559.5};
//
//
//    std::vector<ClassicalWindmillLogo> temps = {temp1};
//
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp5 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp3 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp5 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp2 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp2 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp3 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp5 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp1 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp5 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp1 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp2 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp3 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp3 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp4 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp1 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp1 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp1 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp1 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp4 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp1 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp2 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp1 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp1 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp1 , temps);
//    ClassicalWindmillRecognizer::ComputeLogoHOP ( temp1 , temps);
//
//
//    for ( auto it : temps ) std::cout<<"<------cont----->   "<<it.ContourCenter<<std::endl;
//
//
//    if (  ClassicalWindmillRecognizer::ComputeLogoHOP ( temp4 , temps) ) std::cout << " Yes!!!!!!!!! " <<std::endl;
//    else std::cout << " NO!!!!!!!!! " <<std::endl;
//
//    return 0;
//}



//采样拟合函数
//           sqd = A * sin ( w * t + t0) + b
//           param[0] is A  ||  param[1] is w  ||param[2] is t0
//class sincostfunction{
//public:
//
//    sincostfunction(double _spd,double _t): spd(_spd),t(_t) {};
//
//    template <class T>
//    bool operator()(const T* const param, T* residual) const {
//
//        residual[0] = spd - (
//
//                param[0] * sin ( param[1] * t + param[2]) + 2.090 - param[0]
//
//        );
//        return true;
//    }
//
//private:
//    const double spd;
//    const double t;
//};

//采样拟合函数
//           roll_Angle = -(a/w) * cos(w * t + t0) + (2.09 -a) * t + (a/w) * cos(t0)   #上面函数的积分用计算一定时间内中心点转过的角度
//           param[0] is A  ||  param[1] is w  ||param[2] is t0
//class integral_sincostfunction{
//public:
//
//    integral_sincostfunction(double _roll_Angle,double _t): roll_Angle(_roll_Angle),t(_t) {};
//
//    template <class T>
//    bool operator()(const T* const param, T* residual) const {
//
//        residual[0] = roll_Angle - (
//
//                -(param[0] / param[1]) * cos(param[1] * t + param[2]) + (2.09 - param[0]) * t+ (param[0] / param[1]) * cos(param[2])
//        );
//        return true;
//    }
//
//private:
//    const double roll_Angle;
//    const double t;
//};

//
//bool sleep (uint  m){
//
//
//
//
//}


// 按ESC键，退出系统
// 按Enter键，暂停系统
// 按任意键，继续处理
//int main(int argc, char *argv[])
//{
//    // 初始化日志记录器
//    EasyLogger &logger = EasyLogger::GetSingleInstance();
//    logger.Init();
//
//    // 创建相机
//    HuarayCamera camera;
//
//    // 读取相机参数
//    HuarayCameraParam cameraParam;
//    std::string cameraYaml = "config/infantry_3/basement/huaray_camera_param.yaml";
//    if (!HuarayCameraParam::LoadFromYamlFile(cameraYaml, &cameraParam))
//    {
//        return -1;
//    }
//
//    // 设置相机参数
//    if (!camera.SetParam(cameraParam))
//    {
//        return -1;
//    }
//
////     初始化相机
//    if (!camera.Init())
//    {
//        return -1;
//    }
//
////     打开相机
//    if (!camera.Open())
//    {
//        return -1;
//    }
//
////    // 创建风车识别器
////    ClassicalWindmillRecognizer recognizer;
////
////    // 加载风车识别器参数
////    ClassicalWindmillRecognizerParam recognizerParam;
////    std::string recognizerYaml = "config/infantry_3/basement/classical_windmill_recognizer_param.yaml";
////    if (!ClassicalWindmillRecognizerParam::LoadFromYamlFile(recognizerYaml, &recognizerParam))
////    {
////        return -1;
////    }
////
////    // 设置风车识别器参数
////    if (!recognizer.SetParam(recognizerParam))
////    {
////        return -1;
////    }
////
////    // 初始化风车识别器
////    if (!recognizer.Init())
////    {
////        return -1;
////    }
//
////     创建图像显示窗口
//    cv::namedWindow("rawimage", cv::WINDOW_NORMAL);
//    cv::resizeWindow("rawimage", 800, 600);
////    cv::namedWindow("image", cv::WINDOW_NORMAL);
////    cv::resizeWindow("image", 800, 600);
//
//    // 记录初始化时间戳
//    std::chrono::time_point<std::chrono::steady_clock> initTime = std::chrono::steady_clock::now();
//    uint64_t initTimestamp = initTime.time_since_epoch().count();
//
//    // 初始化数据帧索引和风车扇叶索引
//    uint64_t frameIndex = 0;
//
//    std::vector< std::pair<float, float> > sin_datas;
//    std::vector<float> angle;
//
//    // 获取相机数据
//    HuarayCameraData cameraData;
//    camera.GetData(&cameraData);
//
//    // 循环处理相机数据
//    while (true)
//    {
//        // 记录起始时间戳
//        std::chrono::time_point<std::chrono::steady_clock> beginTime = std::chrono::steady_clock::now();
//        uint64_t beginTimestamp = beginTime.time_since_epoch().count();
//
//
//
////        cv::imshow("rawimage",cameraData.Image);
//
//        // 累加数据帧索引
//        frameIndex++;
//
////        // 原始图像预处理
////        cv::Mat binaryImageFan;
////        cv::Mat binaryImageTarget;
////        recognizer.Preprocess(cameraData.Image, &binaryImageFan, &binaryImageTarget);
////
//////        cv::imshow("binaryImageFan",binaryImageFan);
//////        cv::imshow("binaryImageTarget",binaryImageTarget);
////
////        // 检测风车扇叶集合
////        ClassicalWindmillFan windmillFan;
////        std::vector<ClassicalWindmillFan> targetContours;
////        recognizer.DetectWindmillFans(binaryImageFan, binaryImageTarget, cameraData.Image, &windmillFan, &targetContours);
////
//////        std::cout << " ---------------targetContours_size--------------- " << targetContours.size() << std::endl;
////
////        cv::Mat src(cameraData.Image);
////        // 检索二值图像中的所有轮廓，并填充轮廓的索引结构
////        // cv::findContours()函数使用说明详见：https://www.cnblogs.com/wojianxin/p/12602490.html
////        std::vector<cv::Vec4i> hierarchyFan;
////        std::vector<std::vector<cv::Point>> contoursFan;
////        cv::findContours(binaryImageFan,
////                         contoursFan,
////                         hierarchyFan,
////                         cv::RETR_TREE,
////                         cv::CHAIN_APPROX_NONE,
////                         cv::Point(0, 0));
////
////        cv::Mat tempimag(src.rows,src.cols,CV_8UC1,cv::Scalar(0));
////
//////        for ( auto i : contoursFan )
//////            for ( auto j : i ){
//////
//////                tempimag.at<uchar>(j.y,j.x) = 255;
//////            }
////
////            int i = 5;
////            for (int j = 0 ; j < contoursFan[i].size() ; j ++){
////
////                tempimag.at<uchar>(contoursFan[i][j].y,contoursFan[i][j].x) = 255;
////            }
////
////        cv::imshow(" test_findContours ",tempimag);
////
////
////        // 读取按键的ASCII码；注意：cv::waitKey()返回的是按键的ASCII码
////        int keyValue = cv::waitKey(0);
////
////        // 如果按下ESC键，退出系统
////        if (keyValue == 27)
////        {
////            break;
////        }
////
//////         如果按下Enter键，暂停系统
////        if (keyValue == 13)
////        {
////            cv::waitKey(0);
////        }
//
//        cv::imshow ("rawimage",cameraData.Image);
//
//        int keyValue = cv::waitKey(0);
//
//        // 如果按下ESC键，退出系统
//        if (keyValue == 27)
//        {
//            break;
//        }
//
//    }
//
//    // 关闭相机
//    camera.Close();
//
//    // 释放相机资源
//    camera.Release();
//
//    // 释放风车识别器资源
////    recognizer.Release();
//
//    std::chrono::time_point<std::chrono::steady_clock> endTime = std::chrono::steady_clock::now();
//    uint64_t endTimestamp = endTime.time_since_epoch().count();
//
//    std::cout << "  --------------fdex--------------  " << frameIndex * 1000000000.0f / (endTimestamp - initTimestamp);
//
//    return 0;
//
//}