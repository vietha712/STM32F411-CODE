#ifndef __GPIO_DRIVER_H__
#define	__GPIO_DRIVER_H__

#include <stdint.h>
/*Structure for GPIO register*/
typedef struct {
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AF[2];
}GPIO_Type;

/**********GPIO Base Address***********/
#define		AHB1_BASE	0x40020000U
#define		RCC_BASE	(AHB1_BASE + 0x3800U)

#define		GPIOA_BASE		(AHB1_BASE)
#define		GPIOB_BASE		(AHB1_BASE + 0x0400U)
#define		GPIOC_BASE		(AHB1_BASE + 0x0800U)
#define		GPIOD_BASE		(AHB1_BASE + 0x0C00U)
#define		GPIOE_BASE		(AHB1_BASE + 0x1000U)
#define		GPIOH_BASE		(AHB1_BASE + 0x1C00U)

#define		GPIOA		((GPIO_Type*) GPIOA_BASE)
#define		GPIOB		((GPIO_Type*) GPIOB_BASE)
#define		GPIOC		((GPIO_Type*) GPIOC_BASE)
#define		GPIOD		((GPIO_Type*) GPIOD_BASE)
#define		GPIOE		((GPIO_Type*) GPIOE_BASE)
#define		GPIOH		((GPIO_Type*) GPIOH_BASE)

/*********************************************************/
/*MACRO DEFINITION FOR REGISTER*/

/*MODE REGISTER*/
#define		INPUT_MODE	0x00U
#define		OUTPUT_MODE	0x01U
#define		AF_MODE		0x02U
#define		ANALOG_MODE	0x03U

/*OUTPUT TYPE REGISTER*/
#define		OUT_PUSHPULL	0
#define		OUT_OPENDRAIN	1

/*OUTPUT SPEED REGISTER*/
#define		LOW_SPEED	0x00U
#define		MEDIUM_SPEED	0x01U
#define		FAST_SPEED	0x02U
#define		HIGH_SPEED	0x03U

/*PULL UP PULL DOWN REGISTER*/
#define		NO_PUPD		0x00U
#define		PULL_UP		0x01U
#define		PULL_DOWN	0x02U

/*GPIO CLOCK ENABLE*/
#define		RCC_AHB1ENR	(RCC_BASE + 0x30U)
#define		GPIOA_CLK()	*((uint32_t*)RCC_AHB1ENR) |= (1 << 0)
#define		GPIOB_CLK()	*((uint32_t*)RCC_AHB1ENR) |= (1 << 1)
#define         GPIOC_CLK()     *((uint32_t*)RCC_AHB1ENR) |= (1 << 2)
#define         GPIOD_CLK()     *((uint32_t*)RCC_AHB1ENR) |= (1 << 3)
#define         GPIOE_CLK()     *((uint32_t*)RCC_AHB1ENR) |= (1 << 4)
#define         GPIOH_CLK()     *((uint32_t*)RCC_AHB1ENR) |= (1 << 7)

typedef enum {
	SET,
	RESET
}set_reset;

/*Data structure for gpio pin configuration*/
typedef struct {
	uint32_t mode;
	uint16_t pin;
	uint32_t o_type;
	uint32_t o_speed;
	uint32_t pupd;
}gpio_config;

/*Exposed function*/
void gpio_init(GPIO_Type *GPIOx, gpio_config *pin_info);
void output_set_reset(GPIO_Type *GPIOx, uint16_t pin_num, set_reset state);
uint8_t gpio_read_pin(GPIO_Type *GPIOx, uint16_t pin);
void alternate_conf(GPIO_Type *GPIOx, uint16_t pin, uint16_t alt_func_value);




#endif
