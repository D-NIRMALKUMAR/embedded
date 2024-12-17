#include <regx51.h>
void servo(int a,b);
void delay(int);
void main()
{
while(1)
{
P2_0=1;
servo(0xff,0x19);
P2_0=0;
delay(20000);
/*P2_0=1;
servo(0xfe,0x0c);
P2_0=0;
delay(20000);
P2_0=1;
servo(0xfd,0x4c);
P2_0=0;
delay(20000);
P2_0=1;
servo(0xFC,0x65);
P2_0=0;
delay(20000);
P2_0=1;
servo(0xfb,0x7f);
P2_0=0;
delay(20000);
P2_0=1;
servo(0xfa,0x99);
P2_0=0;
delay(20000);
P2_0=1;
servo(0xf9,0xb2);
P2_0=0;
delay(20000);
*/P2_0=1;
servo(0xf8,0xcc);
P2_0=0;
delay(20000);
/*P2_0=1;
servo(0xf7,0xe5);
P2_0=0;
delay(20000);
P2_0=1;
servo(0xf6,0xff);
P2_0=0;
delay(20000);
P2_0=1;
servo(0xf5,0x42);
P2_0=0;
delay(20000);
*/P2_0=1;
servo(0xf5,0x32);
P2_0=0;
delay(20000);
}
}
void servo(int a,b)
{
TMOD=0x01;
TH0=a;
TL0=b;
TR0=1;
while(TF0==0);
TR0=0;
TF0=0;
}
void delay(int c)
{
int s;
for(s=0;s<=c;s++);
}
