/*
 * GccApplication1.cpp
 *
 * Created: 12/02/2023 7:45:35 PM
 * Author : afschy
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	int num = 1;
	DDRA = 0xFF;
    while (1) 
    {
		PORTA = num;
		num++;
		if(num == 100) num = 0;
		_delay_ms(500);
    }
}

