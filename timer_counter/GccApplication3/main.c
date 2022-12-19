/*
 * GccApplication3.c
 *
 * Created: 12/8/2022 3:16:59 PM
 * Author : SL3
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
int	timeovf = 0;
void timer1_init(int tim){
	sei();
	TCCR1B |= (1<<CS10)|(1<<WGM12);
	TIMSK |= (1 << OCIE1A);
	TCNT1 = 0;
	OCR1A = 16000;
	
	while (1)
	{
		if (timeovf>=tim){
			timeovf = 0;
			cli();
			break;
		}
	}
}

ISR(TIMER1_COMPA_vect){
	timeovf++;
}
int main(void)
{
    /* Replace with your application code */
	DDRC |= (1<<PINC5);

	
    while (1) 
    {
			timer1_init(100);
			PORTC ^= (1<<PINC5);
			timer1_init(100);
		
    }
}
