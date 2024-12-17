#include <reg51.h>
#define a P2
#define b P3
void delay(int d)
{
	int i,j;
	for(i=0;i<d;i++)
	{
		for(j=0;j<1000;j++);
	}
}
void main()
	{
	a=0xff;
	while(1)
	{
		a=0x0a;
		delay(500);
		a=0x05;
		delay(500);
		a=0x0a;
		delay(500);
		a=0x05;
		delay(500);
		b=0xff;
		delay(500);
		b=0x0f;
		delay(500);
		b=0x0f;
		delay(500);
		b=0x0f;
		delay(500);
		b=0x0f;
		delay(500);
		
		
	}
}

		
		