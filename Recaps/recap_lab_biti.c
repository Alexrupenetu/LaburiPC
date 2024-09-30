#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

//Laborator 5 CV: Operatii pe biti

void show_8bits(uint8_t n)
{
	uint8_t mask = 1;
	for(int i=7; i>=0; i--)
		printf("%d", (n &(mask<<i))>>i);
	printf("\n");
}

void show_16bits(uint16_t n)
{
	uint16_t mask = 1;
	for(int i=15; i>=0; i--)
		{
		printf("%d", ((n & (mask<<i))>>i));
		if(i%4 == 0)
			printf(" ");
		}
	printf("\n");
}

void show_32bits(uint32_t n)
{
	uint32_t mask = 1;
	for(int i=31; i>=0; i--)
		{
		printf("%d", ((n & (mask<<i))>>i));
		if(i%4 == 0)
			printf(" ");
		}
	printf("\n");
}

void ex_9(uint8_t n1, uint8_t n2)
{
	char rez = 0; //rez = nibble2 nibble1
	rez = rez | n1;
	rez = rez | (n2<<4);
	show_8bits(rez);
}

void ex_11(int n)
{
	int suma = 0, mask = 1;
	for(int i=0; i<=3; i++)
		suma = suma + ((n & (mask<<i))>>i);
	printf("Suma este %d\n", suma);
}

void ex_13(uint16_t n)
{
	int contor = 0;
	for(int i=0; i<15; i++)
	    if((n & (1<<i)) != 0)
	    	contor++;
	printf("Contor = %d\n", contor);
}

void inverse_nibble8(uint8_t n)
{
	uint8_t mask1 = 0x0F;
	uint8_t mask2 = 0xF0;
	
	uint8_t n1=0, n2=0;
	n1 = n & mask1;
	n2 = n & mask2;
	n = 0;
	n |= (n1<<4) | (n2>>4);
	show_8bits(n);
}

void invers_nibble16(uint16_t n)
{
	//uint16_t = nibble4 nibble3 nibble2 nibble1
	uint16_t mask1 = 0x000F, mask2 = 0x00F0, mask3 = 0x0F00, mask4 = 0xF000;
	uint16_t rez = 0;
	rez |= ((n & mask1)<<12) | ((n & mask2)<<4) | ((n & mask3)>>4) | ((n & mask4)>>12);
	show_16bits(rez);
}

void oglindit_nibble(uint8_t n)
{
	//nibble = abcd -> dcba
	// n = nibble2 nibble1
	uint8_t nibble1 = 0x0F, nibble2 = 0XF0;
	uint8_t a, b, c, d;
	
	nibble1 = n & nibble1;
	nibble2= n & nibble2;
	
	//oglindim nibble1
	d = nibble1 & 1;
	d = d << 3;
	c = nibble1 & (1<<1);
	c = c << 1;
	b = nibble1 & (1<<2);
	b = b >> 1;
	a = nibble1 & (1<<3);
	a = a >> 3;
	nibble1 = 0;
	nibble1 |= d | c | b | a;
	
	//oglindim nibble2
	nibble2 = nibble2 >> 4;
	d = nibble2 & 1;
	d = d << 3;
	c = nibble2 & (1<<1);
	c = c << 1;
	b = nibble2 & (1<<2);
	b = b >> 1;
	a = nibble2 & (1<<3);
	a = a >> 3;
	nibble2 = 0;
	nibble2 |= d | c | b | a;
	
	uint8_t rez=0;
	
	rez |= (nibble2<<4) | nibble1;
	
	show_8bits(rez);
	
}

void ex_15(uint32_t n)
{
	int contor = 1;
	uint32_t mask = 1;
	int prev, curr;
	prev = (n & (mask <<31))>>31;
	for(int i=30; i>=0; i--)
	{
		curr = (n & (mask << i))>>i;
		if(prev != curr)
			contor++;
		prev = curr;
	}
	printf("%d", contor);	
}

void ex_18(uint32_t nr, uint8_t n, int p)
{
	uint32_t mask = 0x000000FF, mask2=n;
	mask = mask << (p * 8);
	mask2 = mask2 << (p*8);
	uint32_t gaura;
	gaura = ~mask;
	nr = nr & gaura;
	nr |= mask2;
	show_32bits(nr);
}
//ex 19 same shit dar pe 64 

void ex_20(uint8_t n1, uint8_t n2)
{
	uint16_t mask1 = n1;
	uint16_t mask2 = n2;
	mask2 = mask2 << 8;
	mask1 |= mask2;
	show_16bits(mask1);
}

void ex_21(uint8_t n3, uint8_t n2, uint8_t n1, uint8_t n0)
{
	uint32_t mask0=n0, mask1=n1, mask2=n2, mask3=n3;
	mask3 = mask3 << 24;
	mask2 = mask2 << 16;
	mask1 = mask1 << 8;
	mask0 |= mask3 | mask2 | mask1;
	show_32bits(mask0);
}

//ex 22 same shit dar pe 64 de biti



//PROBLEME TESTE 

// 1.)Se dau doua numere pe 8 biti, a si b. Sa se construiasca un numar pe 32 de biti astfel: primii 16 reprezinta suma a si b, iar urmatorii 16 modulul diferentei.

void p1(uint8_t a, uint8_t b)
{
	uint32_t mask1 = a+b;
	uint32_t mask2;
	if(a>b)
		mask2 = a-b;
	else
		mask2 = b-a;
	mask2 = mask2<<16;
	
	mask2 |= mask1;
	
	show_32bits(mask2);	
	
}

/*3.)Se da un număr intreg. Sa se implementeze o funcție care returnează un număr pe 8 biti fără semn astfel încât pe cel mai nesemnificativ nibble se stochează numărul cifrelor pare din numărul dat ca parametru, iar pe cel semnificativ se stochează numărul total de cifre din număr. Se va afișa numărul obtinut în hexadecimal cu prefixul “0x”.

Exemplu: Input: 1234567
Output: 0x73
*/

void p3(int n)
{
	int cp=0, c=0;
	while(n)
	{
		if(n%10%2==0)
			cp++;
		c++;
		n=n/10;
	}
	//rez = nibble2 nibble1
	uint8_t nibble1 = cp;
	uint8_t nibble2 = c;
	nibble2 = nibble2 << 4;
	nibble1 |= nibble2;
	printf("0x%0x", nibble1);
}

/*4.)Se citesc numere naturale de la tastatura pana la intalnirea lui 0.Sa se afiseze minimul si media aritmetica a acestor numere.Apoi sa se formeze un numar intreg fara semn pe 32 biti astfel incat pe cei mai semnificativi 16 biti sa se afle media aritmetica ,iar pe cei mai putini semnificativi 16 biti sa se afle minimul. Pentru a calcula minimul dintre 2 numere se foloseste o functie ce primeste 2 parametrii si returneaza minimul.

int minimul(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

uint32_t create_number(int minim, int media)
{
	uint32_t m1 = minim;
	uint32_t m2 = media;
	m2 = m2 <<16;
	uint32_t rez = 0;
	rez |= m1 | m2;
	return rez;
}

int main()
{
	int value, minim=100000000, sum=0, contor=0;
	
	while(1)
	{
		scanf("%d", &value);
		if(value!=0)
		{
			contor++;
			sum = sum + value;
			minim = minimul(value, minim);
		}
		else
		{
		break;
		}
	}
	int media = sum/contor;
	uint32_t rez;
	printf("%d %d \n", minim, media); 
	rez = create_number(minim, media);
	show_32bits(rez);
}

5.) Sa se scrie o functie decode care primeste 2 parametrii: un nr n pe 32 de biti si un nr natural p. Nr n reprezinta data unui an scrisa in felul urmator: primii 4 biti de la dreapta (LSB) reprezinta ziua, urmatorii 4 reprezinta luna, iar restul pana la 32 reprezinta anul. Functia returneaza (in decimal):
ziua, daca p=0
luna, daca p=1
anul, daca p=2
0, daca p>2 

*/

int decode(uint32_t n, int p)  //imi da o eroare si nuj de ce  (Control reaches the end of non-void function)
{
	uint32_t mask_ziua=0x0000000F, mask_luna=0x000000F0, mask_an=0XFFFFFF00;
	int ziua, luna, an;
	if(p == 0)
	{
		ziua = n & mask_ziua;
		return ziua;
	}
	else if(p == 1)
	{
		mask_luna = (n & mask_luna)>>4;
		luna = mask_luna;
		return luna;
	}
	else if(p == 2)
	{
		mask_an = (n & mask_an) >> 8;
		an = mask_an;
		return an;
	}
	else if(p>2)
		return 0;
}

//6.)Sa se scrie o functie care primeste un nr pe 16 biti fara semn, un n si un p si ii inverseaza numarului, n biti incepand de pe pozitia p.

void inversare(uint16_t n, int p)
{
	
}


int main(void)
{
	show_32bits(134565);
	printf("%d", decode(134565, 3));
}




















