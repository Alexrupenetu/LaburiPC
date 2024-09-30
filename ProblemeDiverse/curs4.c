/*
Program care iti scrie un nr nat pe biti
#include<stdio.h>
#include<stdint.h>

void print_bit_8(uint8_t n)
{
uint8_t m;
m = 1<<7;
while(m!=0)
{
 if((n&m) != 0)
 {
 	printf("1");
 }
 else
 {
 	printf("0");
 }
 m = m >> 1;
}
printf("\n");
}

int main(void)
{
uint8_t nr;
printf("nr:");
scanf("%hhX", &nr);
print_bit_8(nr);
}

//problema 2 curs (calculam paritatea pe biti) daca are un nr par de biti de 1 = paritate para pe biti 
                                                        nr impar de biti de 1 = paritate impara pe biti
 o -> paritate para 
 1 -> paritate impara     
 
 printf("%04X", &n); //citim in hexazecimal cu 4 digituri                                                     
*/

#include<stdio.h>
#include<stdint.h>

uint8_t parity(uint8_t n)
{
uint8_t mask = 1;
uint8_t c = 0;

for(int i=0; i<8; i++, mask = mask <<1)
{
	if((n&mask)!=0)
	{
		c++;
	}
}
if((c%2)==0)
   return 0;
else 
   return 1;
}


uint16_t combine6(uint8_t n1, uint8_t n2)
{
return n1 | ((uint16_t)n2 << 8);
}

uint8_t break_byte(uint32_t n, uint8_t b)
{
	return (n>>(8*b)) & 0xFF;
	// byte 0 n = n>>0 & 0xFF
	// byte 1 n = n>>8 & 0xFF
	// byte 2 n = n>>16 & 0xFF
	
}

uint8_t break_nibble(uint32_t n)
{
	return (n>>12) & 0xF;
}

int main(void)
{
 uint8_t nr;
 
 //printf("%08X\n", break_byte(0xA93452B1));
  printf("%08X\n", break_nibble(0xA93452B1));  

}
