#include<reg51.h>

void send(unsigned char *s)
{
    while(*s) {
        SBUF=*s++;
        while(TI==0);
        TI=0;
    }
}

void main()
{
    unsigned int i;
    SCON=0x50;
    TMOD=0x20;
    TH1=TL1=0xfd;
    TR1=1;
    while(1) {
        send("Embetronicx  ");
        for(i=0; i<=35000; i++);
    }
}