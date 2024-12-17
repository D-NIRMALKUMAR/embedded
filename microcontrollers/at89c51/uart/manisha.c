#include <reg51.h>
void Tx_char(unsigned char);
void main()
{
	TMOD=0x20;
	SCON=0x50;
	TH1=0xfd;
	TR1=1;
	Tx_char('h');
	Tx_char('e');
	Tx_char('l');
	Tx_char('l');
	Tx_char('o');
	Tx_char('h');
	Tx_char('i');
	Tx_char('h');
	Tx_char('e');
	Tx_char('l');
	Tx_char('l');
	Tx_char('o');
	while(1);
}
void Tx_char(unsigned char c)
{
SBUF=c;
while(TI==0);
TI=0;
}
	