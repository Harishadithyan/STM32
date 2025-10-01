#include "stm32f4xx.h"
#define GPIOAEN (1U<<0)
#define GPIOBEN (1U<<1)
#define GPIOCEN (1U<<2)
#define LED (1U<<5)
#define LED1 (1U<<1)
#define LED2 (1U<<7)

int main(void){
	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIOBEN;
	RCC->AHB1ENR |= GPIOCEN;
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~ (1U<<11);
	GPIOB->MODER |=(1U<<2);
	GPIOB->MODER &=~ (1U<<3);
	GPIOC->MODER |= (1U<<14);
	GPIOC->MODER &=~ (1U<<15);
	while(1){
		GPIOA->ODR|=LED;
		GPIOB->ODR|=LED1;
		GPIOC->ODR|=LED2;
		delay(50000);
		GPIOA->ODR&=~LED;
		GPIOB->ODR&=~LED1;
		GPIOC->ODR&=~LED2;
		delay(50000);
	}
}

void delay(int n){
	for (int i=0;i<=n;i++);
}
