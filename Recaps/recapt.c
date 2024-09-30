/*1. Se consideră un număr pe 64 de biți citit de la tastatură.
Să se afișeze numărul transformat astfel: la nivel de octet, biții de rang par sunt mutați în nibble-ul inferior, iar
biții de rang impar sunt mutați în nibble-ul superior.
Pentru afișarea numărului și al rezultatului la nivel de biți se va implementa o funcție dedicată.
ex. octet = abcd efgh => aceg bdfh 

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

uint8_t nibble(uint8_t n)
{
uint8_t mask1=0x55, mask2=0xAA, rez=0x00, m1=0x80, m2=0x80;
mask1 = mask1 & n;
mask2 = mask2 & n;
int k=0;
for(int i=0; i<=6; i=i+2)
{
   m2 = 0x80;
   m2 = (m2>>i) & mask2;
   rez = rez | (m2<<(k));
   k++;
}
k=3;
for(int i=1; i<=7; i=i+2)
{
m1 = 0x80;
m1 = (m1>>i) & mask1;
rez = rez | (m1>>k);
k--;
}
return rez;
}

void problema(uint64_t n)
{
uint64_t mask1=0xFF00000000000000, rez=0,mask;
int k=7;
for(int i=0; i<=7; i++)
{
	mask = mask1>>(i*8);
	mask = (mask & n)>>(k*8);
	mask = nibble(mask);
	rez = rez | (mask<<(k*8));
	k--;
}

show_64bits(rez);
}

int main(void)
{
	show_64bits(78234562345623456);
	printf("\n");
	problema(78234562345623456);
}


2. Se citesc de la tastatură numere naturale până la citirea lui 0.
Numerele vor fi stocate într-un tablou folosind o funcție cu antetul:
    void citeste_numar(int *v, int *size, int max),
unde:     v reprezintă tabloul,
              size este dimensiunea curentă,
              max este dimensiunea maximă ce poate fi stocată în v.
Programul va sorta numerele stocate astfel:
    - numerele divizibile cu 3 vor fi plasate la început
    - numerele care dau restul 1 la împărțirea cu 3 vor fi mutate la mijloc
    - numerele care dau restul 2 la împărțirea cu 3 vor fi mutate la final.
Se va implementa o funcție de afișare a vectorului și se va apela după fiecare operație de mutare.
Se vor folosi pointeri pentru rezolvarea problemei, nu indecși.
   
#include<stdio.h>
#define MAX 100

void citeste_numar(int *v, int *size, int max)
{
	int value;
	*size = 0;
	while(1)
	{
	scanf("%d", &value);
	
	if(value!=0)
	{
	*(v+*size) = value;
	*size= *size + 1;
	}
	else if(value==0)
		{
		break;
		}
	else if (*size > max)
		{
		break;
		}
	}
}

void afiseaza_vector(int *v, int *size)
{
	for(int i=0; i<*size; i++)
		printf("%d ", *(v+i));
	printf("\n");
}

void plaseaza_trei(int *v, int *size)
{
	int aux;
	for(int i=0; i<*size-1; i++)
		for(int j=i+1; j<*size; j++)
		 	if(*(v+i)%3!=0 && *(v+j)%3==0)
		 	  {
		 	  	aux = *(v+i);
		 	  	*(v+i)=*(v+j);
		 	  	*(v+j) = aux;
		 	  }
}

int indice3(int *v, int*size)
{
	for(int i=0; i<*size; i++)
		if(*(v+i)%3!=0)
			{
			return i;
			break;
			}
}

void mijloc(int *v, int *size, int indice)
{
	int aux;
	for(int i=indice; i<*size-1; i++)
		for(int j=i+1; j<*size; j++)
			if(*(v+i)%3!=1 && *(v+j)%3==1)
		 	  {
		 	  	aux = *(v+i);
		 	  	*(v+i)=*(v+j);
		 	  	*(v+j) = aux;
		 	  }
}
int main(void)
{
	int v[MAX], size=0;
	citeste_numar(v,&size, MAX); //aici trebuie sa i trimit adresa lui size, fiindca in functie o dereferientiem, gen e un *size adica un pointer dereferentiat, TRE SA AIBA O ADRESA PE CARE SA O DEREFERENTIEZE 
	afiseaza_vector(v, &size);
	plaseaza_trei(v, &size);
	afiseaza_vector(v, &size);
	int indice = indice3(v, &size);
	mijloc(v, &size, indice);
	afiseaza_vector(v, &size);
	
}


3. Se citesc de la tastatura căi către fișiere de pe disk, până la EOF (ctrl+D).
Programul va afișa numele fișierului, eliminând numele directoarelor în care este stocat.
ex. /home/student/pc/lab2/fisier.c -> fisier.c
Pentru rezolvarea problemei se vor folosi următoarele metode:
    1. strtok cu împărțire după '/'
    2. strchr cu căutare după '/'
    3. fără funcții din string.h
*/



























