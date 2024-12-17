#include<reg51.h>
void cct_init(void);
void lcd_init(void);
void lcd_comm(unsigned int);
void lcd_data(char);
char read_switch(void);
char get_switch(void);
void delay(int);
sbit rowa=P1^0;
sbit rowb=P1^1;
sbit rowc=P1^2;
sbit rowd=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;
sbit c4=P1^7;
sbit RS=P3^5;
sbit RW=P3^6;
sbit EN=P3^7;
#define lcd_datapin P2
void main()
{
char key;
cct_init();
lcd_init();
while(1)
{
key=get_switch();
lcd_comm(0x01); //we want to display all char remove this line
lcd_data(key);
}
}
void cct_init()
{
P0=0x00;
P1=0xf0;
P2=0xff;
P3=0xff;
}
void lcd_init()
{
delay(15000);
lcd_comm(0x30);
delay(4500);
lcd_comm(0x30);
delay(300);
lcd_comm(0x30);
delay(650);
lcd_comm(0x38);
lcd_comm(0x06);
lcd_comm(0x0f);
lcd_comm(0x01);
}
void lcd_comm(unsigned int z)
{
RS=0;
RW=0;
lcd_datapin=z;
EN=1;
delay(150);
EN=0;
}
void lcd_data(char t)
{
RS=1;
RW=0;
lcd_datapin=t;
EN=1;
delay(150);
EN=0;
}
char read_switch()
{
rowa=0;rowb=1;rowc=1;rowd=1;
if(c1==0)
{
delay(150);
while(c1==0);
return '0';
}
if(c2==0)
{
delay(150);
while(c2==0);
return '1';
}
if(c3==0)
{
delay(150);
while(c3==0);
return '2';
}
if(c4==0)
{
delay(150);
while(c4==0);
return '3';
}
rowa=1;rowb=0;rowc=1;rowd=1;
if(c1==0)
{
delay(150);
while(c1==0);
return '4';
}
if(c2==0)
{
delay(150);
while(c2==0);
return '5';
}
if(c3==0)
{
delay(150);
while(c3==0);
return '6';
}
if(c4==0)
{
delay(150);
while(c4==0);
return '7';
}
rowa=1;rowb=1;rowc=0;rowd=1;
if(c1==0)
{
delay(150);
while(c1==0);
return '8';
}
if(c2==0)
{
delay(150);
while(c2==0);
return '9';
}
if(c3==0)
{
delay(150);
while(c3==0);
return '10';
}
if(c4==0)
{
delay(150);
while(c4==0);
return '11';
}
rowa=1;rowb=1;rowc=1;rowd=0;
if(c1==0)
{
delay(150);
while(c1==0);
return '12';
}
if(c2==0)
{
delay(150);
while(c2==0);
return '13';
}
if(c3==0)
{
delay(150);
while(c3==0);
return '14';
}
if(c4==0)
{
delay(150);
while(c4==0);
return '15';
}
return '16';
}
char get_switch()
{
char key='16';
while(key=='16')
key=read_switch();
return key;
}
void delay(int a)
{
int i;
for(i=0;i<=a;i++);
}