#include<stdint.h>
#include<util/delay.h>
typedef uint8_t u8;
#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *((volatile u8*)0x39)

#define PINB *((volatile u8*)0x36)
#define DDRB *((uint8_t*)0x37)
#define PORTB *((uint8_t*)0x38)


int main(void)
{
	// sw is input
	 DDRB&=~(1<<0);
	 DDRB&=~(1<<1);
	 DDRB&=~(1<<2);
	// sw is pulled up
	 PORTB|=(1<<0);
	 PORTB|=(1<<1);
	 PORTB|=(1<<2);

	 //led is output,low at start
	DDRA |=(1<<0);
	DDRA |=(1<<1);
	PORTA &=~(1<<0);
	PORTA &=~(1<<1);
	while(1)
	{
		if(PINB&(1<<0)&&PINB&(1<<2))// sw is open
			PORTA&=~(1<<0);
		else // sw is close
			PORTA|=(1<<0);

		if(PINB&(1<<1) &&PINB&(1<<2))// sw is open
			PORTA&=~(1<<1);
		else  // sw is close
			PORTA|=(1<<1);
	}

}
