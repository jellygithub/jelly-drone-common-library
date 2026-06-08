#include "bd_position.h"

#include <cmath>
#include <cstdio>

/**
 * @brief 将角度转换为弧度 / Convert degrees to radians
 * 
 * @param deg 角度 / Degrees
 * @return double 弧度 / Radians
 */
static double deg2rad(double deg) {
    return deg * M_PI / 180.0;
}

int main(int argc, char** argv) {
    // 检查命令行参数，确保提供了授权文件路径
    // Check command line arguments, ensure license file path is provided
    if (argc < 2) {
        std::fprintf(stderr, "用法/Usage: bd_demo_client <license.txt>\n");
        return 2;
    }

    // 从文件中设置授权信息 / Set license information from file
    if (bd_set_license_from_file(argv[1]) != 0) {
        std::fprintf(stderr, "授权错误/License error: %s\n", bd_last_error());
        return 1;
    }

    // 设置相机（无人机）的初始位置和姿态信息
    // Set initial position and attitude of the camera (UAV)
    double cam_lat = 39.7315433568984;    // 相机纬度 / Camera latitude
    double cam_lon = -105.269413228814;   // 相机经度 / Camera longitude
    double cam_h = 34.6413111824459;      // 相机高度 / Camera height (Ellipsoidal Height)
    double yaw = 76.99545;                // 偏航角 / Yaw (degrees)
    double pitch = -45.00122;             // 俯仰角 / Pitch (degrees)
    double distance = 22.0;               // 到目标的直线距离 / Distance to target (meters)

    // 计算目标位置 / Compute target position
    double target_lat = 0.0, target_lon = 0.0, target_h = 0.0;
    int rc = bd_compute_target_position(cam_lat, cam_lon, cam_h, yaw, pitch, distance, &target_lat, &target_lon, &target_h);
    if (rc != 0) {
        std::fprintf(stderr, "计算错误/Compute error: %s\n", bd_last_error());
        return 1;
    }

    // 打印计算出的目标位置 / Print computed target position
    std::printf("目标纬度/Target Lat=%.12f\n", target_lat);
    std::printf("目标经度/Target Lon=%.12f\n", target_lon);
    std::printf("目标高度/Target Alt=%.4f\n", target_h);

    // 预期的真实目标位置（用于验证计算精度）
    // Expected real target position (for accuracy verification)
    double real_lat = 39.7315664987829;
    double real_lon = -105.269231604106;
    double real_alt = 20.3907709756309;

    // 计算计算结果与真实位置之间的误差
    // Compute error between calculated result and real position
    
    // 纬度误差转换为米 (1度约等于111000米)
    // Convert latitude error to meters (1 degree approx 111000m)
    double lat_error = std::fabs(target_lat - real_lat) * 111000.0;
    
    // 经度误差转换为米 (需考虑纬度缩放)
    // Convert longitude error to meters (considering latitude scaling)
    double lon_error = std::fabs(target_lon - real_lon) * 111000.0 * std::cos(deg2rad(real_lat));
    
    // 高度误差 / Altitude error
    double alt_error = std::fabs(target_h - real_alt);
    
    // 计算水平误差和总误差 / Compute horizontal and total error
    double horizontal_error = std::sqrt(lat_error * lat_error + lon_error * lon_error);
    double total_error = std::sqrt(horizontal_error * horizontal_error + alt_error * alt_error);

    // 打印误差结果 / Print error results
    std::printf("水平误差(米)/Horizontal Error(m)=%.3f\n", horizontal_error);
    std::printf("总误差(米)/Total Error(m)=%.3f\n", total_error);
    return 0;
}
