/**
 * freertos_hooks.c — FreeRTOS хуки и базовые настройки
 *
 * Примеры реализации hook-функций для отладки
 * и мониторинга FreeRTOS.
 */

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

void vApplicationStackOverflowHook(TaskHandle_t xTask, char* pcTaskName) {
    /* Критическая ошибка — переполнение стека задачи */
    (void)xTask;
    (void)pcTaskName;
    
    for (;;) {
        /* Здесь можно мигнуть LED или записать в UART */
    }
}

void vApplicationMallocFailedHook(void) {
    /* Ошибка выделения памяти кучей FreeRTOS */
    for (;;) {
        /* Обработка ошибки */
    }
}

void vApplicationIdleHook(void) {
    /* Выполняется в задаче Idle — можно войти в low-power */
    __WFI();  /* Wait For Interrupt */
}

void vApplicationTickHook(void) {
    /* Вызывается каждый тик системного таймера */
    /* Подходит для высокоточного профилирования */
}

void vAssertCalled(const char* pcFile, uint32_t ulLine) {
    /* Обработка assert-ошибок */
    taskENTER_CRITICAL();
    {
        (void)pcFile;
        (void)ulLine;
        for (;;);
    }
    taskEXIT_CRITICAL();
}
