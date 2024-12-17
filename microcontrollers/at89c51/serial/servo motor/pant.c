#include <reg51.h>
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
		a=0x01;
		delay(500);
		a=0x03;
		delay(500);
		a=0x02;
		delay(500);
		a=0x06;
		delay(500);
		a=0x04;
		delay(500);
		a=0x0c;
		delay(500);
		a=0x08;
		delay(500);
		a=0x09;
		delay(500);
		a=0x01;
		delay(500);
		
	}
}
