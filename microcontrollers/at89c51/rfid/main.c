#include<reg51.h>

#define lcd_data P2

sbit rs=P1^5;
sbit rw=P1^6;
sbit en=P1^7;

void lcd_init();
void cmd(unsigned char a);
void dat(unsigned char b);
void show(unsigned char *s);
void lcd_delay();

void ser_init();
void tx(unsigned char t);
unsigned char rx();
void tx_str(unsigned char *s);

unsigned char id[12];
unsigned int i;

void main()
{
  lcd_init();
  ser_init();
  cmd(0x80);
  show("<<SHOW UR CARD>>");
  cmd(0xc0);
  for(i=0; i<12; i++) {
    id[i]=rx();
    dat(id[i]);
  }   
  while(1);
}

void lcd_init()
{
  cmd(0x38);
  cmd(0x0e);
  cmd(0x01);
  cmd(0x06);
  cmd(0x0c);
  cmd(0x80);
}

void cmd(unsigned char a)
{
  lcd_data=a;
  rs=0;
  rw=0;
  en=1;
  lcd_delay();
  en=0;
}

void dat(unsigned char b)
{
  lcd_data=b;
  rs=1;
  rw=0;
  en=1;
  lcd_delay();
  en=0;
}

void show(unsigned char *s)
{
  while(*s) {
    dat(*s++);
  }
}

void lcd_delay()
{
  unsigned int lcd_delay;
  for(lcd_delay=0;lcd_delay<=6000;lcd_delay++);
}

void ser_init()
{
  SCON=0x50;
  TMOD|=0x20;
  TH1=TL1=0xfd;
  TR1=1;
}
unsigned char rx()
{
  while(RI==0);
  RI=0;
  return SBUF;
}

void tx(unsigned char t)
{
  SBUF=t;
  while(TI==0);
  TI=0;
}

void tx_str(unsigned char *s)
{
  while(*s)
    tx(*s++);
}