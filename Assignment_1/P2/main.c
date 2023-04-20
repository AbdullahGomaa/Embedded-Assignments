
#include<stdint.h>
#include<util/delay.h>
typedef uint8_t u8;
#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *((volatile u8*)0x39)


int main(void)
{

   DDRA=255;
	while(1)
	{
		// Pins in PORTA is high
		for(int i=0;i<8;i++)
		{
			PORTA|=(1<<i);
			_delay_ms(300);
		}
		// Pins in PORTA is low
		for(int i=0;i<8;i++)
			{
			    PORTA&=~(1<<i);
			    _delay_ms(300);
			}

	}

	return 0;
}
