#include<stdio.h>
#include<stdint.h>

void show_8bits(uint8_t n)
{
uint8_t mask = 1;

for(int i=7; i>=0; i--)
printf("%d", (n&(mask<<i))>>i);

printf("\n");
}

void inverse_nibble(uint8_t n)
{
uint8_t nibble1=0, nibble2=0, mask=1, rez=0, a, b , c, d; //structura nr pe 8 biti e nibble1 nibble2 
// structura unui nibble = abcd -> dcba

a = n & mask<<7;
a = a>>3;
//show_8bits(a);
b = n & mask << 6;
b = b >> 1;
//show_8bits(b);
c = n & mask << 5;
c = c << 1;
//show_8bits(c);
d = n & mask << 4;
d = d << 3;
//show_8bits(d);

nibble1 |= a|b|c|d;

//printf("nibble1: "); show_8bits(nibble1);

a = n & mask;
a = a<<3;
//show_8bits(a);
b = n & (mask<<1);
b = b<<1;
//show_8bits(b);
c = n & (mask<<2);
c = c>>1;
//show_8bits(c);
d = n & (mask<<3);
d = d>>3;
//show_8bits(d);

nibble2|=a|b|c|d;

//printf("nibble2: "); show_8bits(nibble2);

rez |= nibble1 | nibble2;

printf("rez: "); show_8bits(rez);

}

int main(void)
{
show_8bits(124);
inverse_nibble(124);
return 0;
}
