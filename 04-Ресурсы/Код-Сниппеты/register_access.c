/**
 * register_access.c — Прямой доступ к регистрам STM32
 *
 * Примеры работы с регистрами без HAL/LL.
 * Максимальная производительность, минимальный размер кода.
 */

#include <stdint.h>

/* Адреса регистров GPIOA */
#define GPIOA_BASE      0x40020000UL
#define GPIOA_MODER     (*(volatile uint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_OTYPER    (*(volatile uint32_t*)(GPIOA_BASE + 0x04))
#define GPIOA_OSPEEDR   (*(volatile uint32_t*)(GPIOA_BASE + 0x08))
#define GPIOA_PUPDR     (*(volatile uint32_t*)(GPIOA_BASE + 0x0C))
#define GPIOA_ODR       (*(volatile uint32_t*)(GPIOA_BASE + 0x14))
#define GPIOA_BSRR      (*(volatile uint32_t*)(GPIOA_BASE + 0x18))
#define GPIOA_IDR       (*(volatile uint32_t*)(GPIOA_BASE + 0x10))

/* Адрес RCC для тактирования */
#define RCC_AHB1ENR     (*(volatile uint32_t*)0x40023830UL)
#define RCC_GPIOA_EN    (1U << 0)

void Register_GPIOA_Init(void) {
    /* Включить тактирование GPIOA */
    RCC_AHB1ENR |= RCC_GPIOA_EN;
    
    /* PIN5 — выход (MODER5 = 01) */
    GPIOA_MODER &= ~(0x3U << (5 * 2));
    GPIOA_MODER |=  (0x1U << (5 * 2));
    
    /* Push-Pull (OTYPER5 = 0) */
    GPIOA_OTYPER &= ~(1U << 5);
    
    /* Low speed (OSPEEDR5 = 00) */
    GPIOA_OSPEEDR &= ~(0x3U << (5 * 2));
    
    /* No pull-up/pull-down */
    GPIOA_PUPDR &= ~(0x3U << (5 * 2));
}

void Register_GPIOA_Set(void) {
    GPIOA_BSRR = (1U << 5);  /* Set */
}

void Register_GPIOA_Reset(void) {
    GPIOA_BSRR = (1U << (5 + 16));  /* Reset */
}

uint32_t Register_GPIOA_Read(void) {
    return (GPIOA_IDR >> 5) & 0x01;
}

void Register_GPIOA_Toggle(void) {
    GPIOA_ODR ^= (1U << 5);
}
