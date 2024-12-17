#include <reg51.h>
void delay();                   //5ms delay
void main()
{
    P2=0x00;
    while(1) {
        P2=0xff;
        delay();
        P2=0x00;
        delay();    
    }
}
void delay()
{
        int i;
    for(i=0;i<1000;i++)
    {
        TMOD=0x01;
        TH0=0xee;
        TL0=0x00;
        TR0=1;
        while(TF0==0);
        TF0=0;
    }
}