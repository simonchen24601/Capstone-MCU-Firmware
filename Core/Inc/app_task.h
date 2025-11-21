#pragma once
/* app_task.h - Application task declarations
   Simon Chen 2025
*/

#ifdef __cplusplus
extern "C" {
#endif

// Stub: outputs temperature and humidity readings for now.
void ReportingTaskImpl(void *argument);

// Stub: simulates motion interrupts (prints motion events).
void InterruptHandlerTaskImpl(void* argument);

#ifdef __cplusplus
}
#endif
