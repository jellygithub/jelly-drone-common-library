#pragma once

#include <stddef.h>

#if defined(_WIN32)
#  if defined(BD_POSITION_BUILD)
#    define BD_API __declspec(dllexport)
#  else
#    define BD_API __declspec(dllimport)
#  endif
#else
#  define BD_API __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

BD_API int bd_set_license(const char* license_text);
BD_API int bd_set_license_from_file(const char* license_path);

BD_API int bd_compute_target_position(double cam_lat,
                                      double cam_lon,
                                      double cam_h,
                                      double yaw,
                                      double pitch,
                                      double distance,
                                      double* target_lat,
                                      double* target_lon,
                                      double* target_h);

BD_API const char* bd_last_error();

#ifdef __cplusplus
}
#endif
