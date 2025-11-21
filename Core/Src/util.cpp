#include "util.h"
#include <cstdint>
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

extern UART_HandleTypeDef huart2;
extern osMutexId_t UARTWriteMtxHandle;

HAL_StatusTypeDef WriteUART_TS(const void* data, size_t size)
{
    HAL_StatusTypeDef ret;
    if (osMutexAcquire(UARTWriteMtxHandle, osWaitForever) == osOK) {
        ret = HAL_UART_Transmit(&huart2, (uint8_t*)data, size, 100);
        osMutexRelease(UARTWriteMtxHandle);
    } else {
        ret = HAL_ERROR;
    }
    return ret;
}

HAL_StatusTypeDef ReadUART(void* data, size_t size)
{
    return HAL_UART_Receive(&huart2, (uint8_t*)data, size, 100);
}