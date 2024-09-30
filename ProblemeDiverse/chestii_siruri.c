/*Se citeste un text dintr un fisier numit caca.txt care contine mai multi separatori.
Transformarea va fi urm: Ana!!!Vino aici   . Esti tu??? -> Ana!Vino aici. Esti tu???

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	FILE *f=NULL;
	char *pathname = "caca.txt";
	char text[80]="Ana!!!are mere.   Maria,, tu esti????!", sep[5]=" ,!?.";
	
	if((f = fopen(pathname, "r")) == NULL)
	{
		perror(NULL);
		eixt(-1);
	}
	
	fgets(text, 50, f);
	
	int l = strlen(text);
	
	for(int i=0; i<l-1; i++)
		if(strchr(sep, text[i])!=0 && text[i]==text[i+1])
			{
			strcpy(text+i, text + i + 1);
			i--;
			l--;}
			
	if(fclose(f) != 0)
	{
		perror(NULL);
		exit(-1);
	}		
	
	FILE *f2 = NULL;
	
	if((f2 = fopen("rezz.txt", "w"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
}


EXEMPLE STANGACIU LAB 13 fisiere 
ex1: să se scrie un program care citește de la tastatură un n întreg și scrie într-un fișier cu numele ”out.txt” pentru fiecare număr din intervalul [0,n] dacă este par sau impar



#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n;
	FILE *f=NULL;
	char *pathname = "out.txt";
	
	scanf("%d", &n);
	
	if((f = fopen(pathname, "w"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	for(int i=0; i<=n; i++)
	{	
		if(i%2==0)
			fputs("par ", f); // fprintf(f, "%d este par\n", i);
		else
			fputs("impar ", f); //frpintf(f, "%d este impar\n", i);
	}
	fclose(f);
}


ex2: un fișier conține pe fiecare linie coordonatele unor puncte în plan (x,y), definite prin numere reale. Să se citească aceste puncte într-un vector alocat dinamic, astfel încât să ocupe memoria minimă necesară, iar apoi să se afișeze perechea de puncte care sunt cele mai depărtate unele de altele




#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
double x,y;
}pct;

FILE *f = NULL;
pct *puncte;
int nr_p=0;


double dist(pct p1, pct p2)
{
	double dx, dy;
	dx = p1.x-p2.x;
	dy = p1.y - p2.y;
	
	double distanta = sqrt(dx*dx + dy*dy);
	return distanta;
}


int main(void)
{
	double x,y;
	if((f = fopen("test.txt", "r"))==NULL)
	{
		perror(NULL);
		exit(-1); 
	}
	
	if((puncte = malloc(sizeof(pct)))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	while(fscanf(f, "%lg %lg", &x, &y)==2)
	{
		if((puncte = (pct*)realloc(puncte, sizeof(pct)*(nr_p+1)))==NULL)
		{
			printf("Memorie insuficienta");
			free(puncte);
			fclose(f);
			exit(-1);
		}
		
		puncte[nr_p].x = x;
		puncte[nr_p].y = y;
		nr_p++;
	}
	
	fclose(f);
	
	double dMax=0, d;
	int iMax, jMax;
	
	for(int i=0; i<nr_p; i++)
		for(int j=i+1; j<nr_p; j++)
			{
				d = dist(puncte[i],puncte[j]);
				if(d>dMax)
				{
				dMax = d;
				iMax = i;
				jMax = j;
				
				}
			}
			
	printf("Punctele cele mai departate sunt A(%g, %g) si B(%g, %g)\n", puncte[iMax].x, puncte[iMax].y, puncte[jMax].x, puncte[jMax].y);
	free(puncte);
}



ex3: Să se citească dintr-un fișier toate liniile de text, să se elimine liniile vide, să se sorteze alfabetic și se se scrie liniile rezultate într-un fișier de ieșire. O linie poate avea maxim 1000 de caractere. Liniile citite vor fi memorate într-un vector alocat dinamic 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **linii;
int n_linii;
FILE *fin = NULL;
FILE *fout = NULL;

void eliberare()
{
	for(int i=0; i<n_linii; i++)
		free(linii[i]);
	free(linii);
	fclose(fin);
	fclose(fout);
}

void adauga_linie(const char *linie)
{
 	//iau o variabila linie_noua in care copiez linia citita ca sa pot sa i aloc spatiu 
 
	 char *linie_noua;
	 if((linie_noua = (char*) malloc(sizeof(strlen(linie)+1)*sizeof(char)))==NULL)
	 {
	 	printf("Memorie insuficienta");
	 	eliberare();
	 	exit(-1);
	 }
	 strcpy(linie_noua, linie);
	 
	 char **p;
	 //fac loc pt inca o linie, folosesc o variabila intermediara p 
	 if((p = (char**)realloc(linii, sizeof(char*)*(n_linii+1)))==NULL)
	 {
	 	printf("Memorie insuficienta");
	 	free(linie_noua);
	 	eliberare();
	 	exit(-1);
	 }
	 linii = p;
	 linii[n_linii] = linie_noua;
	 n_linii++;
}

int cmp(const void *p1, const void *p2)
{
	return strcmp(*(char **)p1, *(char**)p2);
}

int main(void)
{

	char linie[1000];
	
	if((fin = fopen("test.txt", "r"))==NULL)
	{
		printf("Eroare la deschidere fisier");
		exit(EXIT_FAILURE);
	}
	
	while(fgets(linie, 1000, fin) != NULL)
	{
	
	if(strlen(linie)<=1) continue; //continue asta practic face ca daca linia e vida sa dea skip peste adauga
	adauga_linie(linie);
	
	}
	
	qsort(linii, n_linii, sizeof(char*), cmp);
	
	//scrie liniile sortate in fout
	
	for(int i=0; i<n_linii; i++)
		fputs(linii[i], fout);
		
	fclose(fout);
	eliberare();
}



*/





























