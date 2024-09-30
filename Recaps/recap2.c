/*1. Se consideră un număr pe 64 de biți citit de la tastatură.
Să se afișeze numărul transformat astfel: la nivel de octet, biții de rang par sunt mutați în nibble-ul inferior, iar
biții de rang impar sunt mutați în nibble-ul superior.
Pentru afișarea numărului și al rezultatului la nivel de biți se va implementa o funcție dedicată.
ex. octet = abcd efgh => aceg bdfh */

#include<stdio.h>
#include<stdint.h>

void show_8bits(uint8_t n)
{
uint8_t mask=1;
for(int i=7; i>=0; i--)
{
printf("%d", (n & (mask<<i))>>i );
if(i%4==0)
printf("%c", ' ');
}
}

void show_64bits(uint64_t n)
{
uint64_t mask=1;
for(int i=63; i>=0; i--)
{
printf("%ld", (n & (mask<<i))>>i);
if(i%8==0)
printf("%c", ' ');
}
printf("\n");
}

void nibble(uint8_t n)
{
uint8_t mask1=0x55, mask2=0xAA, rez=0x00, m1=0x80, m2=0x80;
mask1 = mask1 & n;
mask2 = mask2 & n;
int k=0;
for(int i=0; i<=6; i=i+2)
{
	 printf("A i este %d\n", i);
	
	   m2=0x80;
	   m2 = (m2>>i) & mask2;
	   rez = rez | (m2<<(k));
	   k++;
}
k=3;
for(int i=0; i<=3; i++)
{
	printf("B i este %d\n ", i);
	
	m1 = 0x80;
	m1 = (m1>>(2*i+1)) & mask1;
	rez = rez | (m1>>k);
	k--;
}
show_8bits(rez);
}

void problema(uint64_t n)
{
uint64_t mask=0xFF00000000000000, rez=0, caca;
int k=7;
//for(int i=0; i<=7; i++)

	mask = 0xFF00000000000000;
	mask = (mask & n)>>7*8;
	show_64bits(mask);
	printf("\n");
	nibble(mask);
}

int main(void)
{
	//problema(9878234562345623456);
	show_8bits(0xB5);
	printf("\n");
	nibble(0xB5);
}

