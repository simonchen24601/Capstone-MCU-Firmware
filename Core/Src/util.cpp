#include "util.h"
#include <cstdint>
#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef huart2;



HAL_StatusTypeDef WriteUART_TS(const void* data, size_t size)
{

    auto ret = HAL_UART_Transmit(&huart2, (uint8_t*)data, size, 100);
    
    return ret;
}

HAL_StatusTypeDef ReadUART(void* data, size_t size)
{
    return HAL_UART_Receive(&huart2, (uint8_t*)data, size, 100);
}