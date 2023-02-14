/*
 * Instruction_memory.cpp
 *
 * Created: 12/02/2023 11:44:44 AM
 * Author : afschy
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t reverse_bits(uint8_t num) {
	uint8_t reversed = 0;
	for(int i=0; i<=7; i++) {
		uint8_t temp = num & (1 << i);
		temp = temp >> i;
		reversed = reversed | (temp << (7-i));
	}
	return reversed;
}

uint16_t instruction_memory[] = {
	0x8015, 0x9122, 0xc213
};

int main(void)
{
    MCUCSR = (1<<JTD);  MCUCSR = (1<<JTD);
	DDRB = 0x00;	// Program counter input
	
	// Top 8 bits: A0 - A7, A0 is MSB
	// Bottom 8 bits: C7 - C0, C7 is MSB
	DDRA = 0xff;
	DDRC = 0xff;
	
	uint8_t pc = -1, top_8_bits, bottom_8_bits;
	uint16_t instruction;
    while (1) 
    {
		if(pc == PINB) continue;
		pc = PINB;
		instruction = instruction_memory[pc];
		bottom_8_bits = uint8_t(instruction);
		top_8_bits = reverse_bits(uint8_t(instruction >> 8));
		PORTA = top_8_bits;
		PORTC = bottom_8_bits;
		_delay_ms(50);
    }
}

