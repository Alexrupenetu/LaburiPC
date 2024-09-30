// Online C compiler to run C program online
#include <stdio.h>
#include <stdint.h>

void show_bits(uint8_t nr)
{
  uint8_t mask = 0b10000000;
  uint8_t i = 0;
  for (i = 0; i < 8; i++)
    {
      if ((nr & mask) == 0)
        {
          printf ("0");
        }
      else
        {
          printf ("1");
        }
      mask = mask >> 1; // mask >>= 1;
    }
  printf ("\n");
}


void show(uint16_t nr)
{
  uint16_t mask = 0b1000000000000000;
  uint16_t i = 0;
  for (i = 0; i < 16; i++)
    {
      if ((nr & mask) == 0)
        {
          printf ("0");
        }
      else
        {
          printf ("1");
        }
      mask = mask >> 1; // mask >>= 1;
    }
  printf ("\n");
}

void ex8lab(uint8_t n)
{
    uint8_t mask=1;
    n = n|(1<<0);
    n = n &~(1<<1);
    n = n|(1<<2);
    n = n|(1<<3);
    n = n^(1<<4);
    n = n&~(1<<5);
    n = n&~(1<<6);
    n = n^(1<<7);
    
    show_bits(n);
}

void ex9lab(uint8_t a, uint8_t b)
{
    uint8_t rez=0, m=15;
    rez = rez | b;
    rez = rez | (a<<4);
    
    show_bits(rez);
    printf("\n");
    printf("%d", rez&15) ;
}

void ex10lab(uint8_t n)
{
   show_bits(n>>7);
}

void ex11lab(uint8_t n)
{
    int s=0;
    for(int i=0; i<4; i++)
    {
        if((n&(1<<i))!=0)
           s=s+1;
    }
    printf("%d", s);
}

void ex14(uint16_t n)
{
    uint16_t nibble1 = 0XF000, nibble2, nibble3, nibble4, rez=0;
    nibble1 = nibble1&n;
    nibble1 = nibble1>>12;
    nibble2 = 0XF000>>4;
    nibble2 = nibble2 & n;
    nibble2 = nibble2>>4;
    nibble3 = 0XF000>>8;
    nibble3 = nibble3 & n;
    nibble3 = nibble3 <<4;
    nibble4 = 0XF000>>12;
    nibble4 = nibble4 & n;
    nibble4 = nibble4<<12;
    
    rez = (((rez | nibble1) | nibble2) | nibble3) | nibble4;
   
    show(rez);
    
}

void oglindit(uint8_t n)
{
	uint8_t mask = 1, rez = 0, k1=7, k2=1, bit;
	for(int i=0; i<7; i++)
	{
		if(i<4)
		{
			bit = ((mask<<i)&n)<<k1;
			k1 = k1 - 2;
		}
		if(i>=4)
		{
			bit = ((mask<<i)&n)>>k2;
			k2 = k2 + 2;
		}
		rez |= bit;
	}
	show_bits(rez);
}


int main() {
    show_bits(21);
    oglindit(21);
    return 0;
}







