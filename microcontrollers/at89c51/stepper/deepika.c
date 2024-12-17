#include<reg51.h>
#define L293D P2
void delay(int b);
void main()
{
    P2=0x00;
    while(1)
    {
        L293D=0x01;
        delay(100);
        L293D=0x03;
        delay(1000);
        L293D=0x02;
        delay(1000);
        L293D=0x06;
        delay(1000);
        L293D=0x04;
        delay(1000);
        L293D=0x0c;
        delay(1000);
        L293D=0x08;
        delay(1000);
        L293D=0x09;
        delay(1000);
        L293D=0x01;
        delay(1000);
    }
}
void delay(int b){
	int i;
	int j;
    for(i=0;i<b;i++){
        for(j=0;j<100;j++);
    }
}
     