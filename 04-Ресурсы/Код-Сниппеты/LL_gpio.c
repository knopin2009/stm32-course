/**
 * LL_gpio.c — Примеры работы с GPIO через LL-драйверы
 *
 * Low-Layer API обеспечивает прямой доступ к регистрам
 * с минимальными накладными расходами.
 */

#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_rcc.h"

void LL_GPIO_Init_Demo(void) {
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = LL_GPIO_PIN_5;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void LL_GPIO_SetDemo(void) {
    LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5);
}

void LL_GPIO_ResetDemo(void) {
    LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5);
}

void LL_GPIO_ToggleDemo(void) {
    LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_5);
}

uint8_t LL_GPIO_ReadInputDemo(GPIO_TypeDef* GPIOx, uint32_t Pin) {
    return LL_GPIO_IsInputPinSet(GPIOx, Pin);
}
