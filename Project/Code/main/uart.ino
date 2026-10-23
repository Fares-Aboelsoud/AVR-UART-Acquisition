#define F_CPU 16000000UL
#include <avr/io.h>
#include "uart.h"

void Uart_SetBaudRate(unsigned short BaudRate) {
    unsigned short UBRR = ((F_CPU / 16UL) / BaudRate) - 1;   /*Baud Rate Calculation*/
    UBRR0L = (unsigned char)(UBRR & 0xFF);      /* UBRR0L holds the 8 least significant bits [7:0] */
    UBRR0H = (unsigned char)((UBRR >> 8) & 0x0F);     /* UBRR0H holds the 4 most significant bits [11:8] */
}

void Uart_Init(void) {
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);    /*Activating Receiver and Transmitter in UCSR0B*/
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);    /*Set character size to 8 bit*/
    Uart_SetBaudRate(9600);     /*Set Baud Rate to 9600*/
}

void Uart_SendChar(unsigned char DataByte) {
    while (!(UCSR0A & (1 << UDRE0)));    /*Wait until UDRE0 bit in UCSR0A is 1*/
    UDR0 = DataByte;     /*Write byte to UDR0 to transmit*/
}

unsigned char Uart_IsDataAvailable(void) {
    return (UCSR0A & (1 << RXC0));     /*Returns the unread data in the receiver buffer*/
}

unsigned char Uart_ReadData(void) {
    while (!Uart_IsDataAvailable());    /*Wait until data is available*/
    return UDR0;         /*return UDR0 contents*/
}

void Uart_SendString(char DataString[], unsigned char Size) {
    unsigned char i;
    for (i = 0; i < Size; i++) {   /*As long as i is less than Size (the full word), it will add the next letter*/
        Uart_SendChar(DataString[i]);
    }    
}