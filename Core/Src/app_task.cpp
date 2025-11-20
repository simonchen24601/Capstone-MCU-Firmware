#include "app_task.h"
#include <cstring>
#include <cstdio>
#include "util.h"
#include "cmsis_os.h"

void ReportingTaskImpl(void *argument)
{
    float temp = 25.0f;
    float hum = 50.0f;
    int counter = 0;

    while (true) {
        temp = 25.0f + (float)(counter % 10) * 0.1f;   // 25.0 .. 25.9
        hum  = 50.0f + (float)(counter % 20) * 0.2f;   // 50.0 .. 53.8

        static char buf[64];
        sprintf(buf, "[StubSensor] Temperature=%.2f C, Humidity=%.2f %%\r\n", temp, hum);
        WriteUART(buf, strlen(buf));
        counter++;

        osDelay(5000);
    }
}

void InterruptHandlerTaskImpl(void* argument)
{
    bool busy_flag;
    int motion_counter = 0;

    while (true) {
        busy_flag = false;

        if ((motion_counter % 40) == 0) {
            /* Simulate a motion trigger */
            printf("[StubMotion] Motion detected!\r\n");
            busy_flag = true;
        }

        motion_counter++;

        if (!busy_flag) {
            osDelay(50);
        }
    }
}
