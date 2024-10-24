#include <stm32l475xx.h>

void delayBy10ms(uint32_t k){

	for (uint32_t i = 0; i < (k * 200000) ; i++); // to create time delay i calculate clock period * 4 * N = time delay

}

int main(){

	RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	
	GPIOA -> MODER &= ~GPIO_MODER_MODE0;
	GPIOA -> MODER |= GPIO_MODER_MODE0_0; //Set pin 0 of port A to output
	
	while(1){
		
		GPIOA -> BSRR |= GPIO_BSRR_BS0;
		delayBy10ms(1);
		GPIOA -> BSRR |= GPIO_BSRR_BR0;
		delayBy10ms(1);
	
	}
	
	return 0;

}