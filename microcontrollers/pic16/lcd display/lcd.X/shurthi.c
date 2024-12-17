#include <pic.h>
#include <htc.h>
#define lcd_data RB
#define rs RC0
#define rw RC1
#define en RC2
void lcd_init();
void cmd(unsigned char a);
void dat(unsigned char b);
void show(unsigned char *s);
void lcd_delay();
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
    PORTB=a;
    rs=0;
    rw=0;
    en=1;
    lcd_delay();
    en=0;
}
void dat(unsigned char b)
{
    PORTB=b;
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
    for(lcd_delay=0;lcd_delay<=600;lcd_delay++);
}
int main()
{
    TRISB=0;
    TRISC=0;
    unsigned int j;
    lcd_init();
    while(1) {
        cmd(0x80);
        show("   Welcome  ");
        cmd(0xc0);
        show(" LIVE WIRE ");
        for(j=0; j<30000; j++);
        cmd(0x01);
        for(j=0; j<3000; j++);
    }
}
