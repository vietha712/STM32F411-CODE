#include <gpio_driver.h>

/***Static function***/

static void gpio_pin_mode(GPIO_Type *GPIOx, uint16_t pin_num, uint8_t mode) {
  GPIOx->MODER |= (mode << (pin_num*2));
}

static void gpio_out_type(GPIO_Type *GPIOx, uint16_t pin_num, uint8_t out_type) {
  GPIOx->OTYPER |= (out_type << pin_num);
}

static void gpio_out_speed(GPIO_Type *GPIOx, uint16_t pin_num, uint8_t speed) {
  GPIOx->OSPEEDR |= (speed << (pin_num*2));
}

static void gpio_pupd(GPIO_Type *GPIOx, uint16_t pin_num, uint8_t pupd_sel) {
  GPIOx->PUPDR |= (pupd_sel << (pin_num*2));
}

/***Exposed function***/
void gpio_init(GPIO_Type *GPIOx, gpio_config *pin_info) {
  gpio_pin_mode(GPIOx, pin_info->pin, pin_info->mode);
  gpio_out_type(GPIOx, pin_info->pin, pin_info->o_type);
  gpio_out_speed(GPIOx, pin_info->pin, pin_info->o_speed);
  gpio_pupd(GPIOx, pin_info->pin, pin_info->pupd);
}

void output_set_reset(GPIO_Type *GPIOx, uint16_t pin, set_reset state) {
  if (state == SET){
    GPIOx->BSRR |= (1 << pin);
  }
  else if (state == RESET){
    GPIOx->BSRR |= (1 << (pin + 16U));
  }
  else{;}
}

uint8_t gpio_read_pin(GPIO_Type *GPIOx, uint16_t pin) {
  uint8_t value;

  value = ((GPIOx->IDR) & (1<<pin)) >> pin;
  
  return value;
}

void alternate_conf(GPIO_Type *GPIOx, uint16_t pin, uint16_t alt_func_value){
   if (pin <= 7) {
	GPIOx->AF[0] |= (alt_func_value << (pin * 4));		
   }
   else {
   	GPIOx->AF[1] |= (alt_func_value << ((pin % 8) * 4));
   }
}

