# BD Target Position Client Demo 

> **学习免费，商用每月15元，支持买断。密钥联系作者：675223307@qq.com，腾讯QQ群号：791977435

### 1. 项目简介
`bd_client_demo` 是一个用于无人机目标位置计算的 C++ 示例项目。本项目演示了如何集成 `bd_position` SDK，通过无人机当前的经纬高、姿态（偏航角、俯仰角）以及目标距离，精确计算出目标的地理坐标。


### 2. 核心功能
- **精确坐标计算**：基于 WGS84 椭球模型，通过相机参数计算目标经纬高。
- **跨平台支持**：预编译支持 `x86_64` 和 `aarch64` (如 NVIDIA Jetson) 架构。

### 3. 快速上手
- **构建**：使用 CMake 进行构建。
- **运行**：运行程序需提供有效授权签名 `license.txt`。
- **网络**：必须联网以通过时间校验。

### 4. 授权说明
- 授权签名，请联系作者：675223307@qq.com，QQ 群：791977435。
- **授权核心**：包含过期时间、授权对象及数字签名。

---



### 1. Project Introduction

 Free for learning; 15 RMB/month for commercial use. Contact: 675223307@qq.com, QQ Group: 791977435

`bd_client_demo` is a C++ sample project for UAV (Unmanned Aerial Vehicle) target position calculation. This project demonstrates how to integrate the `bd_position` SDK to accurately calculate the geographic coordinates of a target using the UAV's current latitude, longitude, altitude, attitude (yaw, pitch), and the distance to the target.


### 2. Core Features
- **Precise Coordinate Calculation**: Calculates target LLA (Lat, Lon, Alt) based on the WGS84 ellipsoid model and camera parameters.
- **Secure License Verification**: Supports RSA256 signature-based license file validation.
- **Anti-Cheating Mechanism**: Mandates internet time for license expiration checks. If the device is offline, verification will fail, preventing users from bypassing limits by modifying local system time.
- **Cross-Platform Support**: Pre-compiled libraries available for both `x86_64` and `aarch64` (e.g., NVIDIA Jetson) architectures.

### 3. Directory Structure
```text
bd_client_demo/
├── include/              # SDK Headers
│   └── bd_position.h     # API for calculation and licensing
├── lib/                  # Pre-compiled Libraries
│   ├── aarch64/          # ARM Architecture (Jetson, etc.)
│   └── x86_64/           # X86 Architecture (PC, Server)
├── src/                  # Source Code
│   └── main.cpp          # Demo application with detailed comments
├── CMakeLists.txt        # Build configuration
└── README.md             # Project documentation
```

### 4. Quick Start
- **Build**: Build using CMake.
- **Run**: Running the program requires a valid authorization signature `license.txt`.
- **Network**: Internet connection is mandatory for time verification.

### 5. Licensing
- For authorization signatures, please contact the author: 675223307@qq.com, QQ Group: 791977435.
- **License Content**: Includes expiration time, authorized subject, and digital signature.

### 6. API Quick Reference
```cpp
// 1. Set License
int rc = bd_set_license_from_file("license.txt");

// 2. Compute Target Position
rc = bd_compute_target_position(
    cam_lat, cam_lon, cam_h,  // UAV LLA
    yaw, pitch, distance,      // Attitude and distance
    &target_lat, &target_lon, &target_h // Output results
);
```

### 7. License
The sample code is released under the MIT License. For the dynamic library, please follow the relevant commercial licensing agreements.
