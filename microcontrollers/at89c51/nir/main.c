#include<reg51.h>
void cmd(unsigned int);
void lcd_data(unsigned char);
void delay(int);
void lcd_init();
void cmd_data(unsigned int,unsigned char*);
sbit RS=P1^0;
sbit RW=P1^1;
sbit EN=P1^2;
#define lcd_datapin P2
void main()
{
while(1)
{
lcd_init();
cmd_data(0x38,"LIVEWIRE");
cmd_data(0xc4,"WELCOME");
}
}
void lcd_init()
{
cmd(0x38);
cmd(0x0c);
cmd(0x06);
cmd(0x01);
cmd(0x80);
}
void cmd(unsigned int comm)
{
lcd_datapin=comm;
RS=0;
RW=0;
EN=1;
delay(10);
EN=0;
}
void lcd_data(unsigned char dat)
{
lcd_datapin=dat;
RS=1;
RW=0;
EN=1;
delay(10);
EN=0;
}
void cmd_data(unsigned int comm,unsigned char* dat)
{
cmd(comm);
while(*dat)
{
lcd_data(*dat ++);
}
}
void delay(int a)
{
int i,j;
for(i=0;i<=a;i++)
for(j=0;j<=1000;j++);
}