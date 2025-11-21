#include "app_task.h"
#include <cstring>
#include <cstdio>
#include "util.h"
#include "cmsis_os.h"

void ReportingTaskImpl(void *argument)
{
    /* Use integer fixed-point (value * 100) to avoid floats. */
    int temp_x100 = 2500; // 25.00 * 100
    int hum_x100 = 5000;  // 50.00 * 100
    int counter = 0;

    while (true) {
        /* temp: 25.00 .. 25.90 in steps of 0.10 -> x100: 2500 .. 2590 */
        temp_x100 = 2500 + (counter % 10) * 10;   // 2500 .. 2590
        /* hum: 50.00 .. 53.80 in steps of 0.20 -> x100: 5000 .. 5380 */
        hum_x100  = 5000 + (counter % 20) * 20;   // 5000 .. 5380

        int t_int = temp_x100 / 100;
        int t_frac = temp_x100 % 100;
        int h_int = hum_x100 / 100;
        int h_frac = hum_x100 % 100;

        static char buf[64];
        sprintf(buf, "[StubTemperatureSensor] Temperature=%d.%02dC, Humidity=%d.%02d%%\r\n",
                t_int, t_frac, h_int, h_frac);
        WriteUART_TS(buf, strlen(buf));
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

        if ((motion_counter % 200) == 0) {
            /* Simulate a motion trigger */
            static char buf[64];
            sprintf(buf, "[StubMotionSensor] Motion detected at count %d\r\n", motion_counter);
            WriteUART_TS(buf, strlen(buf));
            busy_flag = true;
        }

        motion_counter++;

        if (!busy_flag) {
            osDelay(50);
        }
    }
}
