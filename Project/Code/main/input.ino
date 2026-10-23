#include <avr/io.h>
#include "input.h"

void Input_Init(void) {
    DDRD &= ~(1 << BUTTON_PIN);     /*Set BUTTON_PIN as Input*/
    DDRD |= (1 << LED_PIN);     /*Set LED_PIN as Output*/
    PORTD &= ~(1 << LED_PIN);     /*LED's initial state is LOW*/
}

unsigned char Button_State(void) {
    return ((PIND & (1 << BUTTON_PIN)) != 0);    /*Read BUTTON_PIN state*/
}

void LED_On(void) {
    PORTD |= (1 << LED_PIN);    /* Set LED_PIN HIGH*/
}

void LED_Off(void) {
    PORTD &= ~(1 << LED_PIN);     /*Set LED_PIN LOW*/
}