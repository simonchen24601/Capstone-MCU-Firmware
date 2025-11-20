/* util.h - Utility functions and definitions
Simon Chen 2025
*/
#pragma once
#include "stm32f4xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

HAL_StatusTypeDef WriteUART_TS(const void* data, size_t size);

HAL_StatusTypeDef ReadUART(void* data, size_t size);

#ifdef __cplusplus
}
#endif
