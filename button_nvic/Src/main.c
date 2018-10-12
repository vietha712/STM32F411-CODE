#include <button_nvic.h>

void EXTI0_IRQHandler(void){
  LED_toggle(GPIOD, LED);
  *((uint32_t*) EXTI_PR) |= (1 << 0);
  *((uint32_t*) NVIC_ICPR0) |= (1 << 6);
}

void main(void)
{
  led_init();
  button_init();
  EXTI_init();
  while(1)
    {
      

    }
}
