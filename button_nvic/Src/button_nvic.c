#include <button_nvic.h>

void led_init() {
  GPIOD_CLK();
  
  gpio_config led_info;
  led_info.mode = OUTPUT_MODE;
  led_info.pin  = LED;
  led_info.o_type = OUT_PUSHPULL;
  led_info.o_speed = MEDIUM_SPEED;
  led_info.pupd = NO_PUPD;
  gpio_init(GPIOD, &led_info);
}

void button_init() {
  GPIOA_CLK();
  
  gpio_config button_info;
  button_info.mode = INPUT_MODE;
  button_info.pin  = button;
  gpio_init(GPIOA, &button_info);
}

void EXTI_init() {
  *((uint32_t*) RCC_APB2) |= (1 << 14);
  *((uint32_t*) SYSCFG_EXTICR1) |= (0x0000U << 0);

  *((uint32_t*) EXTI_IMR)  |= (1 << 0);
  *((uint32_t*) EXTI_RTSR) |= (1 << 0);
  /*NVIC*/
  *((uint32_t*) NVIC_ISER0) |= (1 << 6);
  *((uint32_t*) NVIC_IPR1)  &= ~(0xFF << 16);//clear 8 bit from 0
  *((uint32_t*) NVIC_IPR1)  |= (0x01 << 22); //set preemption 1-1-0-0-0-0-0-0
  asm("cpsie i");
}

void led_on(uint16_t pin) {
  output_set_reset(GPIOD, pin, SET);
}

void led_off(uint16_t pin) {
  output_set_reset(GPIOD, pin, RESET);
}

void LED_toggle(GPIO_Type *GPIOx,uint16_t pin) {
  uint8_t state = gpio_read_pin(GPIOx, pin);
  if (state == 1){
    led_off(pin);
  }
  else if (state == 0) {
    led_on(pin);
  }
  else {;}
}
