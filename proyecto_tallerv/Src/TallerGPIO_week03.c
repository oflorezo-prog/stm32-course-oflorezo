/*
 * TallerV2GPIO.c
 *  Created on: May 22, 2026
 *      Author: Oscar
 */
#include "stdint.h"
#include "stm32f4xx.h"
#include "stdio.h"
//variables
uint8_t variable = 0;
uint8_t num1 = 10; //num1 debe ser mayor a num2
uint8_t num2 = 5;
char op = '/'; // '' si es una palabra y "" si son más de una
uint8_t resultado = 0;
uint8_t led0 = 0;
uint8_t led1 = 0;
uint8_t led2 = 0;
uint8_t led3 = 0;
uint8_t led4 = 0;
uint8_t led5 = 0;
uint8_t led6 = 0;
uint8_t led7 = 0;

//cabecera funciones
void init_RCC(void);
void init_PORTA(void);
void init_PORTB(void);
void init_PORTC(void);
int calcular (uint8_t num1, uint8_t num2, char op);
void mostrar(void);
int main(void){

	init_RCC();
	init_PORTA();
	init_PORTB();
	init_PORTC();
	resultado = calcular(num1, num2, op);



	return 0;
}

//Definicion funciones
void init_RCC(void){
	RCC->AHB1ENR |= (0b1 << 0);  //encender la señal de reloj del GPIOA
	RCC->AHB1ENR |= (0b1 << 1);  //encender la señal de reloj para GPIOB
	RCC->AHB1ENR |= (0b1 << 2);  //GPIOC
}

void init_PORTA(void){
	/*para el PA5*/
	GPIOA->MODER &= ~(0b11 << 5*2); //limpiar el registro de moders
	GPIOA->MODER |= (0b1 << 5*2); //poner (0,1) en moders

	GPIOA->OTYPER &= ~(0b1 << 5);
	GPIOA->OSPEEDR &= ~(0b11 << 5*2);
	GPIOA->OSPEEDR |= (0b1 << 5*2);
	GPIOA ->PUPDR &= ~(0b11 << 5*2);
	GPIOA->ODR |= (0b1 <<5);
	/*PA6*/
	GPIOA->MODER &= ~(0b11 << 6*2); //limpiar el registro de moders
	GPIOA->MODER |= (0b1 << 6*2); //poner (0,1) en moders

	GPIOA->OTYPER &= ~(0b1 << 6);
	GPIOA->OSPEEDR &= ~(0b11 << 6*2);
	GPIOA->OSPEEDR |= (0b1 << 6*2);
	GPIOA ->PUPDR &= ~(0b11 << 6*2);
	GPIOA->ODR |= (0b1 <<6);

	/*PA7*/
	GPIOA->MODER &= ~(0b11 << 7*2); //limpiar el registro de moders
	GPIOA->MODER |= (0b1 << 7*2); //poner (0,1) en moders

	GPIOA->OTYPER &= ~(0b1 << 7);
	GPIOA->OSPEEDR &= ~(0b11 << 7*2);
	GPIOA->OSPEEDR |= (0b1 << 7*2);
	GPIOA ->PUPDR &= ~(0b11 << 7*2);
	GPIOA->ODR |= (0b1 <<7);
	/*PA8*/
	GPIOA->MODER &= ~(0b11 << 8*2); //limpiar el registro de moders
	GPIOA->MODER |= (0b1 << 8*2); //poner (0,1) en moders

	GPIOA->OTYPER &= ~(0b1 << 8);
	GPIOA->OSPEEDR &= ~(0b11 << 8*2);
	GPIOA->OSPEEDR |= (0b1 << 8*2);
	GPIOA ->PUPDR &= ~(0b11 << 8*2);
	GPIOA->ODR |= (0b1 <<8);
	GPIOA->MODER &= ~(0b11 << 6*2); //limpiar el registro de moders
	GPIOA->MODER |= (0b1 << 6*2); //poner (0,1) en moders

	GPIOA->OTYPER &= ~(0b1 << 9);
	GPIOA->OSPEEDR &= ~(0b11 << 9*2);
	GPIOA->OSPEEDR |= (0b1 << 9*2);
	GPIOA ->PUPDR &= ~(0b11 << 9*2);
	GPIOA->ODR |= (0b1 <<9);
}
void init_PORTB(void){
	/*para el PA6*/
	GPIOB->MODER &= ~(0b11 << 6*2); //limpiar el registro de moders
	GPIOB->MODER |= (0b1 << 6*2); //poner (0,1) en moders

	GPIOB->OTYPER &= ~(0b1 << 6);
	GPIOB->OSPEEDR &= ~(0b11 << 6*2);
	GPIOB->OSPEEDR |= (0b1 << 6*2);
	GPIOB ->PUPDR &= ~(0b11 << 6*2);
	GPIOB->ODR |= (0b1 <<6);
	/*PA8*/
	GPIOB->MODER &= ~(0b11 << 8*2); //limpiar el registro de moders
	GPIOB->MODER |= (0b1 << 8*2); //poner (0,1) en moders

	GPIOB->OTYPER &= ~(0b1 << 8);
	GPIOB->OSPEEDR &= ~(0b11 << 8*2);
	GPIOB->OSPEEDR |= (0b1 << 8*2);
	GPIOB ->PUPDR &= ~(0b11 << 8*2);
	GPIOB->ODR |= (0b1 <<8);

	/*9
	 */
	GPIOB->MODER &= ~(0b11 << 9*2); //limpiar el registro de moders
	GPIOB->MODER |= (0b1 << 9*2); //poner (0,1) en moders

	GPIOB->OTYPER &= ~(0b1 << 9);
	GPIOB->OSPEEDR &= ~(0b11 << 9*2);
	GPIOB->OSPEEDR |= (0b1 << 9*2);
	GPIOB ->PUPDR &= ~(0b11 << 9*2);
	GPIOB->ODR |= (0b1 <<9);

}
void init_PORTC(void){
	/*para el PA6*/
	GPIOC->MODER &= ~(0b11 << 7*2); //limpiar el registro de moders
	GPIOC->MODER |= (0b1 << 7*2); //poner (0,1) en moders

	GPIOC->OTYPER &= ~(0b1 << 7);
	GPIOC->OSPEEDR &= ~(0b11 << 7*2);
	GPIOC->OSPEEDR |= (0b1 << 7*2);
	GPIOC ->PUPDR &= ~(0b11 << 7*2);
	GPIOC->ODR |= (0b1 <<7);
}

int calcular(uint8_t num1, uint8_t num2, char op){
    if (op == '+'){
        return num1 + num2;
    }

    else if (op == '-'){
        return num1 - num2;
    }

    else if (op == '*'){
            return num1 * num2;
        }

    else if (op == '/'){
            return num1 / num2;
        }

    else{
        return 0;
    }
void mostrar(void){
	led0 = (resultado >> 0) & (0b1);
	led1 = (resultado >> 1) & (0b1);
	led2 = (resultado >> 2) & (0b1);
	led3 = (resultado >> 3) & (0b1);
	led4 = (resultado >> 4) & (0b1);
	led5 = (resultado >> 5) & (0b1);
	led6 = (resultado >> 6) & (0b1);
	led7 = (resultado >> 7) & (0b1);
	if(led0){
		GPIOB->ODR |= (0b1 << 8);
	}
	else{
		GPIOB->ODR &= ~(0b1 << 8);
	}
	if(led1){
		GPIOB->ODR |= (0b1 << 7);
	}
	else{
		GPIOB->ODR &= ~(0b1 << 7);
	}
	if(led2){
		GPIOB->ODR |= (0b1 << 6);
	}
	else{
		GPIOB->ODR &= ~(0b1 << 6);
	}
	if(led3){
		GPIOB->ODR |= (0b1 << 5);
	}
	else{
		GPIOB->ODR &= ~(0b1 << 5);
	}
	if(led4){
		GPIOB->ODR |= (0b1 << 4);
	}
	else{
		GPIOB->ODR &= ~(0b1 << 4);
	}
	if(led5){
		GPIOB->ODR |= (0b1 << 3);
	}
	else{
		GPIOB->ODR &= ~(0b1 << 3);
	}
	if(led6){
		GPIOB->ODR |= (0b1 << 2);
	}
	else{
		GPIOB->ODR &= ~(0b1 << 2);
	}
	if(led7){
		GPIOB->ODR |= (0b1 << 1);
	}
	else{
		GPIOB->ODR &= ~(0b1 << 1);
	}

}


