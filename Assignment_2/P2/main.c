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
		 DDRA&=~(1<<0);
		 DDRA&=~(1<<1);
		// sw is pulled up
		 PORTA|=(1<<0);
		 PORTA|=(1<<1);
	u8 segmnetCathod[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F},number=0;
		DDRB=255;
		PORTB=0;

	while(1)
	{
		if(((PINA>>0)&1)==0)
		{
			_delay_ms(100);
			if(((PINA>>0)&1)==0 &&number<9)
			    number++;

		}
		if(((PINA>>1)&1)==0 &&number!=0)
		{
			_delay_ms(100);
			if(((PINA>>1)&1)==0 &&number!=0)
			    number--;
		}
		PORTB=segmnetCathod[number];



	}
}
