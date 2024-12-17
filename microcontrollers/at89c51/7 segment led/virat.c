#include<reg51.h>
#define a P2

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
		a=0x3f;
		delay(500);
		a=0x06;
		delay(500);
		a=0x5b;                                           
		delay(500);
		a=0x4f;
		delay(500);
		a=0x66;
		delay(500);
		a=0x6d;
		delay(500);
		a=0x7c;
		delay(500);
		a=0x07;
		delay(500);
		a=0xff;
		delay(500);
		a=0x67;
		delay(500);
		
	}
}
		
		