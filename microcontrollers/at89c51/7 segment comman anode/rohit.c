#include<reg51.h>
#define a P2

void delay(int d)
{
	int i,j;
	for(i=0;i<d;i++)
	{
		for(j=0;j<500;j++);
	}
}
void main()
{
	a=0xff;
	while(1)
	{
		a=0x40;
		delay(1000);
		a=0x79;
		delay(1000);
		a=0x24;                                           
		delay(1000);
		a=0x30;
		delay(1000);
		a=0x19;
		delay(1000);
		a=0x12;
		delay(1000);
		a=0x03;
		delay(1000);
		a=0x78;
		delay(1000);
		a=0x00;
		delay(1000);
		a=0x18;
		delay(1000);
		
	}
}