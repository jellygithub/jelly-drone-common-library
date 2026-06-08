# BD Target Position Client Demo 

### 1. 项目简介
`bd_client_demo` 是一个用于无人机目标位置计算的 C++ 示例项目。本项目演示了如何集成 `bd_position` SDK，通过无人机当前的经纬高、姿态（偏航角、俯仰角）以及目标距离，精确计算出目标的地理坐标。

本项目集成了安全授权机制，支持 RSA 加密签名校验，并强制通过互联网时间进行授权过期验证，确保商业化交付的安全性。

### 2. 核心功能
- **精确坐标计算**：基于 WGS84 椭球模型，通过相机参数计算目标经纬高。
- **安全授权验证**：支持基于 RSA256 签名的许可证（License）校验。
- **反作弊机制**：强制获取互联网时间进行授权校验，若设备未联网则直接授权失败，防止通过修改系统时间绕过限制。
- **跨平台支持**：预编译支持 `x86_64` 和 `aarch64` (如 NVIDIA Jetson) 架构。

### 3. 快速上手
- **构建**：使用 CMake 进行构建。
- **运行**：运行程序需提供有效的 `license.txt`。
- **网络**：必须联网以通过时间校验。

### 4. 授权说明与定价
- **定价方案**：每月 15 元，支持买断，具体请联系作者：675223307@qq.com。
- **授权核心**：包含过期时间、授权对象及数字签名。

---



### 1. Project Introduction
`bd_client_demo` is a C++ sample project for UAV (Unmanned Aerial Vehicle) target position calculation. This project demonstrates how to integrate the `bd_position` SDK to accurately calculate the geographic coordinates of a target using the UAV's current latitude, longitude, altitude, attitude (yaw, pitch), and the distance to the target.

The project features a secure licensing mechanism with RSA signature verification and mandatory internet-based time validation to ensure the security of commercial deliveries.

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

#### Requirements
- CMake (>= 3.16)
- C++ Compiler (C++11 support)
- **Internet Connection**: Mandatory. The program requires internet access to verify time; being offline will cause licensing to fail.

#### Build
```bash
cd bd_client_demo
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j
```

#### Run
An authorized `license.txt` is required to run the program:
```bash
./bd_demo_client ../license.txt
```

### 5. Licensing & Pricing
- **Pricing**: 15 RMB per month, or a one-time buyout. Please contact the author: **675223307@qq.com**.
- **License Content**: Includes expiration time (exp), subject (sub), and a digital signature.

To obtain a formal license, please contact the author: 675223307@qq.com.

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
