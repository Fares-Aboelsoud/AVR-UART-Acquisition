#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "input.h"

int main(void) {
    Input_Init();      /*Initialize Button and LED pins*/
    Uart_Init();      /*Iitialize UART*/
    unsigned char old_button = 0;     /*First button state is LOW*/
    char word[10];     /*To store typed characters*/
    unsigned char i = 0;

    while (1) {
        unsigned char new_button = Button_State();

        if (new_button != old_button) {     /*Check if the button state changed*/
            if (new_button == 1) {       /*Check if button's current state is HIGH*/
                Uart_SendString("Button is pushed\n", 17);
            } else {
                _delay_ms(200);
                Uart_SendString("Button is released\n", 19);
            }
            old_button = new_button;    /*Updates button's state*/
        }

        if (Uart_IsDataAvailable()) {
            char f = Uart_ReadData();
            if (f == '\n' || f == '\r') {
                word[i] = '\0';           /*End the word when enter is pressed*/
                if (strcmp(word, "LED on") == 0)  LED_On(); /*if word = "LED on", LED turns on*/
                if (strcmp(word, "LED off") == 0) LED_Off(); /*if word = "LED off", LED turns off*/
                i = 0;            /* Reset for next word */
            } 
            else {
                word[i++] = f;      /*Add the next letter to "word"*/
            }
        }
    }
    return 0;
}