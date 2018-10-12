#ifndef __BUTTON_NVIC_H__
#define __BUTTON_NVIC_H__

#include <gpio_driver.h>

#define button 0
#define LED   15

/*EXTI register*/
#define EXTI_BASE 0x40013C00U
#define EXTI_IMR  (EXTI_BASE + 0x00U)
#define EXTI_RTSR (EXTI_BASE + 0x08U)
#define EXTI_PR   (EXTI_BASE + 0x14U)

/*SYSCFG external interrupt configuration register 1*/
#define SYSCFG_BASE 0x40013800U
#define SYSCFG_EXTICR1 (SYSCFG_BASE + 0x08U)
#define RCC_APB2 (0x40023800U + 0x44U)

/*NVIC REGISTER*/
#define NVIC_ISER0 0xE000E100U
#define NVIC_ICPR0 0xE000E280U
#define NVIC_IPR1  0xE000E404U

void led_init();
void button_init();
void EXTI_init();
void led_on(uint16_t pin);
void led_off(uint16_t pin);
void LED_toggle(GPIO_Type *GPIOx, uint16_t pin);
void EXTI0_IRQHandler(void);

#endif
