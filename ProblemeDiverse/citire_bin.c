#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>

/* LABORATOR 13
1.Se considera un fisier binar ce contine numere intregi pe 4 bytes. Programul nu va cunoaste dimensiunea fisierului. Sa se scrie un program ce citeste un astfel de fisier si scrie numerele citite intr-un alt fisier in format text hexazecimal cu 8 cifre hexa cate unul pe rand. 

int main(void)
{
FILE *f = NULL;
FILE *out = NULL;

//4 bytes = 32 biti
uint32_t n;

if((f = fopen("integers.bin", "rb"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
if((out = fopen("rez.txt", "w"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
while( fread(&n, sizeof(uint32_t), 1, f) == 1 )
{
	fprintf(out, "%08X\n", n);
}

if(fclose(f)!=0)
	{
		perror(NULL);
		exit(-1);
	}
if(fclose(out)!=0)
	{
		perror(NULL);
		exit(-1);
	} 
	
return 0;

}

2.Se considera un fisier binar ce contine numere intregi pe 4 bytes. Programul nu va cunoaste dimensiunea fisierului. Sa se scrie un program format din mai multe functii: o functie ce citeste un astfel de fisier si stocheaza numerele intr-un tablou. O functie care sorteaza acest tablou in ordine descrescatoare, o functie ce scrie un astfel de tablou intr-un alt fisier in format text, fiecare numar in zecimal pe un alt rand. 

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define CHUNK 1000

uint32_t *vector = NULL;

void citire(int *size)
{

FILE *f;

uint32_t number;

int len = CHUNK, index =0;


if((vector = (uint32_t*)malloc(sizeof(uint32_t)*len))==NULL)
	{
	perror(NULL);
	exit(-1);
	}


if((f = fopen("integers.bin", "rb"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
while( fread(&number, sizeof(uint32_t), 1, f) == 1)
{
	
	if(index == len)
		{
			len = len + CHUNK;
			
			if((vector = (uint32_t *)realloc(vector, sizeof(uint32_t)*len))==NULL)
				{
					perror(NULL);
					exit(-1);
				}
		}
		
	vector[index] = number;
	index++;
}

if((vector = (uint32_t*)realloc(vector, index * sizeof(uint32_t))) == NULL)
{
	perror(NULL);
	exit(-1);
}
*size = index;

if(fclose(f) !=0)
	{
		perror(NULL);
		exit(-1);
	}

}

void sortare(int size)
{
	uint32_t aux;
	for(int i=0; i<size-1; i++)
		for(int j= i + 1; j<size; j++)
			if(vector[i]<vector[j])
				{
				aux = vector[i];
				vector[i] = vector[j];
				vector[j] = aux;
				}
}

void scriere(int size)
{
	FILE *out = NULL;
	
	if((out = fopen("rez.txt", "w")) == NULL)
		{
			perror(NULL);
			exit(-1);
		}
		
	for(int i=0; i<size; i++)
		fprintf(out, "%u\n", vector[i]);
		
	if(fclose(out) !=0)
	{
		perror(NULL);
		exit(-1);
	}
	free(vector);
}


int main()
{
int size=0;

//nr pe 4 bytes -> 32 biti

citire(&size);
sortare(size);
scriere(size);

}

PROBLEMA 3

FILE *src = NULL;
FILE *dest = NULL;

void copiere(FILE *src, FILE *dest)
{
		int number;
		if((src = fopen("integers.bin", "rb")) == NULL)
		{
			perror(NULL);
			exit(-1);
		}
		
		if((dest = fopen("rez.txt", "wb")) == NULL)
		{
			perror(NULL);
			exit(-1);
		}
		
		while(fread(&number, sizeof(uint32_t), 1, src) == 1)
		{
			fprintf(dest, "%04X ", number);
		}
		fclose(src);
		fclose(dest);
}


int main(void)
{
	copiere(src, dest);
}

*/


typedef struct 
{
uint16_t an;
uint8_t luna;
uint8_t zi;
uint8_t idx_senzor;
uint16_t valoare;
}Data;

uint32_t contor;

FILE *src = NULL;
FILE *dest = NULL;

void creare_fisier(FILE *src)
{
	if((src = fopen("test_senzori.bin", "wb"))==NULL)
	{
	perror(NULL);
	exit(-1);
	}
	
	contor = 6;
	
	Data Inregistrare1 = {2004, 9, 15, 1, 545};
	Data Inregistrare2 = {2004, 10, 12, 1, 200};
	Data Inregistrare3 = {2005, 11, 16, 2, -1902};
	Data Inregistrare4 = {2005, 12, 8, 2, 100};
	Data Inregistrare5 = {2006, 10, 11, 2, 125};
	Data Inregistrare6 = {2004, 9, 14, 3, 1234};
	
	fwrite(&contor, sizeof(uint32_t), 1, src);
	
	fwrite(&Inregistrare1, sizeof(Data), 1, src);
	fwrite(&Inregistrare2, sizeof(Data), 1, src);
	fwrite(&Inregistrare3, sizeof(Data), 1, src);
	fwrite(&Inregistrare4, sizeof(Data), 1, src);
	fwrite(&Inregistrare5, sizeof(Data), 1, src);
	fwrite(&Inregistrare6, sizeof(Data), 1, src);
	
	fclose(src);
		
}

void citire_fisier(FILE *src)
{
	if((src = fopen("test_senzori.bin", "rb")) == NULL)
	{
	perror(NULL);
	exit(-1);
	}
	
	fread(&contor, sizeof(uint32_t), 1, src);
	
	for(int i=1; i<=contor; i++)
	{
	Data Inregistrare;
	fread(&Inregistrare, sizeof(Data), 1, src);
	
	printf("Inregistrare%d: An:%u, Luna:%u, Zi:%u, Idx:%u, Valoare:%u \n", i,
	Inregistrare.an, Inregistrare.luna, Inregistrare.zi, Inregistrare.idx_senzor, Inregistrare.valoare);
	
	}
	fclose(src);
}

void afisare_valori_an_luna(uint16_t an, uint8_t luna)
{
	Data Inregistrare;
	
	if((src = fopen("test_senzori.bin", "rb")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	fread(&contor, sizeof(uint32_t), 1, src);
	
	for(int i=1; i<=contor; i++)
	{
	fread(&Inregistrare, sizeof(Data), 1, src);
	if(Inregistrare.an == an || Inregistrare.luna == luna)
		printf("%u ", Inregistrare.valoare);
	}
	printf("\n");
	fclose(src);
}


int main(void)
{

creare_fisier(src);
citire_fisier(src);
afisare_valori_an_luna(2004, 12);
}





















