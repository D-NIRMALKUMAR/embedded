#include <reg51.h>
#define a P2
void delay(int d)
{
	int i,j;
	for (i=0;i<d;i++)
	{
		for (j=0;j<1000;j++);
	}
}
void main()
{
	a=0xff;
	while(1)
	{
		a=0xff;
		delay(1000);
		a=0x7f;
		delay(1000);
		a=0x3f;
		delay(1000);
		a=0x1f;
		delay(1000);
		a=0x0f;
		delay(1000);
		a=0x07;
		delay(1000);
		a=0x03;
		delay(1000);
		a=0x01;
		delay(1000);
		a=0x00;
		delay(1000);
	}
}