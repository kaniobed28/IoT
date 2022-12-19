/*
 * GccApplication4.c
 *
 * Created: 12/12/2022 1:41:45 PM
 * Author : SL3
 */ 

#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)
#include <util/delay.h>

void uart_init (void)
{
	UBRRH=(BAUDRATE>>8);
	UBRRL=BAUDRATE;                         //set baud rate
	UCSRB|=(1<<TXEN)|(1<<RXEN);             //enable receiver and transmitter
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);// 8bit data format
}
// function to send data - NOT REQUIRED FOR THIS PROGRAM IMPLEMENTATION
void uart_transmit (unsigned char data)
{
	while (!( UCSRA & (1<<UDRE)));            // wait while register is free
	UDR = data;                             // load data in the register
}
unsigned char uart_recieve (void)
{
	while(!((UCSRA) & (1<<RXC)));                   // wait while data is being received
	return UDR;                                   // return 8-bit data
}
int main(void)
{
    /* Replace with your application code */
	uart_init();
    while (1) 
    {
		//_delay_ms(200);
		uart_transmit('a');
		//_delay_ms(100);
		//uart_recieve();
    }
}

