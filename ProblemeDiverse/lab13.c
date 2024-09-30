//PROBLEMA I 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Movie //e mai comod sa ti numesti typedeful la fel ca structul ca sa nu te incurci, e perfect legal
{
char *titlu;
int an;
int buget;
}Movie;
Movie *m;
int nr_movies=0;
void sortare_an()
{
	Movie aux;
	for(int i=0; i<nr_movies-1; i++)
		for(int j=i+1; j<nr_movies; j++)
			if(m[i].an>m[j].an)
			{
			aux=m[i];
			m[i]=m[j];
			m[j]=aux;
			}
}

void afisare(FILE *out)
{
	for(int i=0; i<nr_movies; i++)
		fprintf(out, "%d-%s ", m[i].an, m[i].titlu);
}
int main(void)
{
	FILE *f = NULL;
	char *filename = "movies.csv";
	
	if((f=fopen(filename, "r"))==NULL)
	{
	perror(NULL);
	exit(-1);
	}
	
	char linie[1000];
	fgets(linie, 1000, f); //citim prima linie fara sa o prelucram fiindca n are cifre
	
	while(fgets(linie,1000,f)!=NULL) //Observam ca datele pe care trebuie sa le salvam in struct trebuie sa fie pe pozitiile 1(an), 3(titlu) si 7(buget), asa ca impartim fiecare linie in cuvinte si le luam pe alea care trebe
	{
		int poz=1;
		char *p=strtok(linie, ",");
		//ne asiguram ca incap datele noi in structul nostru, pe care il realocam dinamic la fiecare parcurgere de linie 
		if((m = (Movie*)realloc(m, sizeof(Movie)*(nr_movies+1)))==NULL)
		{
		printf("ERROR!");
		exit(-1);
		}
		
		while(p!=NULL)
		{
			if(poz==1)
			{
				m[nr_movies].an = atoi(p);
			}
			
			if(poz==3)
			{
				//alocam dinamic in struct ca sa fim siguri ca incape 
				if((m[nr_movies].titlu =(char *)malloc(sizeof(char)*(strlen(p)+1)))==NULL)
				{
				printf("ERROR!");
				exit(-1);
				}
				strcpy(m[nr_movies].titlu, p);
			}
			if(poz==7)
			{
				m[nr_movies].buget = atoi(p);
			}
			poz++; //numara cuvinte din linie 
			p = strtok(NULL, ",");
		}
		nr_movies++;
		//numara liniile, adica nr de elemente din struct
	}
	fclose(f); //inchidem fisierul
	
	sortare_an();
	FILE *f2=NULL;
	char *filename2 = "out1.txt";
	if((f2=fopen(filename2, "w"))==NULL)
	{
		printf("ERROR!");
		exit(-1);
	}
	afisare(f2);
	fclose(f2); //basically de abia dupa ce inchizi fisierul sunt scrise informatiile in el deci E FT IMPORTANT fclose
	
	// E bine să eliberezi memoria pentru fiecare titlu înainte de a elibera memoria pentru structura Movie.
	for (int i = 0; i < nr_movies; i++) 
	    {
		free(m[i].titlu);
	    }
	free(m);	
}

/*
//PROBLEMA II
#include<stdio.h>
#include<stdlib.h>

#define CHUNK 10

int main(void)
{
	int *v, current_size, index=0, size;
	current_size = CHUNK;
	
	if((v = malloc(sizeof(int) * current_size))==NULL)
	{
	printf("ERROR");
	exit(-1);
	}
	
	int aux;
	
	scanf("%d", &aux);
	
	while(aux!=0)
	{
		v[index]=aux;
		index++;
		
		if(index == current_size)
		{
		current_size = current_size + CHUNK;
		if((v = realloc(v, sizeof(int)*current_size))==NULL)
		{
			printf("ERROR");
			exit(-1);
		}
		}
		scanf("%d", &aux);
	}
	
	if((v = realloc(v, sizeof(int)*index))==NULL)
	{
		printf("ERROR");
		exit(-1);
	}
	size = index;
	
	FILE *f=NULL;
	char *filename = "out.txt";
	
	if((f=fopen(filename, "w"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	for(int i=0; i<size; i++)
		fprintf(f, "%d|", v[i]);
	
	fclose(f);
	free(v);
}

PROBLEMA III
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Cream un struct care sa retina datele de care avem nevoie: judet, beneficiari platiti, suma totala

struct MyStruct
{
char *judet;
int beneficiari, suma;
};

struct MyStruct *p;
int contor = 0;

void sortare_lexicografic()
{
	struct MyStruct aux;
	
	for(int i=0; i<contor-1; i++)
		for(int j=i; j<contor; j++)
			if(strcmp(p[i].judet, p[j].judet)>0) //adica s1 e mai mare ca s2
			{
			aux = p[i];
			p[i]=p[j];
			p[j]=aux;
			}
			
}

void sortare_suma()
{
	struct MyStruct aux;
	
	for(int i=0; i<contor-1; i++)
		for(int j=i; j<contor; j++)
			if(p[i].suma>p[j].suma) 
			{
			aux = p[i];
			p[i]=p[j];
			p[j]=aux;
			}
}

int main(void)
{
	FILE *f = NULL;
	
	if((f=fopen("indemnizatie.csv", "r"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	char linie[1000];
	
	fgets(linie, 1000, f);
	
	int pop_curenta, pop_max=0, indice_pop;
	int sum_curenta, sum_max=0, indice_sum;
	 
	if((p = (struct MyStruct *)malloc(sizeof(struct MyStruct)))==NULL)
		{
			perror(NULL);
			exit(-1);
		}
	
	while(fgets(linie, 1000, f)!=NULL)
	{
		if((p = (struct MyStruct *)realloc(p, sizeof(struct MyStruct) * (contor + 1)))==NULL)
			{
			perror(NULL);
			exit(-1);
			}
	
		int poz = 1;
		char *token = strtok(linie, ";");
		
		while(token!=NULL)
		{
			if(poz == 1) //judet
			{
				if((p[contor].judet = (char *)malloc(sizeof(char) * (strlen(token)+1)))==NULL)
				{
					perror(NULL);
					exit(-1);
				}
				strcpy(p[contor].judet, token);
			}
			if(poz == 2)//Populatie
			{
				pop_curenta = atoi(token);
				if(pop_curenta>pop_max)
				{
					pop_max = pop_curenta;
					indice_pop = contor;
					
				}
			}
			if(poz == 3)
			{
				p[contor].beneficiari = atoi(token);
			}
			if(poz == 5)
			{
				p[contor].suma = atoi(token);
			}
			if(poz == 6)
			{
				sum_curenta = atoi(token);
				if(sum_curenta>sum_max)	
				{
				sum_max = sum_curenta;
				indice_sum = contor;
				}		
			}
			
			poz++;
			
			token = strtok(NULL, ";");
		}
		
		contor++;
	}
	fclose(f);
	
	FILE *f2;
	char *pathname = "rezultat.txt";
	
	if((f2 = fopen(pathname, "w"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	fprintf(f2, "%s\n%s", p[indice_pop].judet, p[indice_sum].judet);
	fclose(f2);
	
	for(int i=0; i<contor; i++)
		free(p[i].judet);
	free(p);
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **linii;
int n_linii;

FILE *f = NULL;

void eliberare()
{
	for(int i=0; i<n_linii; i++)
	 	free(linii[i]);
	 free(linii);
}

void adauga(const char *linie)
{
	char *new_line;
	
	if((new_line = (char*)malloc(sizeof(char) * (strlen(linie)+1))) == NULL)
	{
		printf("Memorie insuficienta");
		eliberare();
		exit(EXIT_FAILURE);	
	} 
	
	strcpy(new_line, linie);
	
	char **p;
	if((p = (char **)realloc(linii, sizeof(char*) * (n_linii + 1))) == NULL)
	{
		printf("Memorie insuficienta");
		eliberare();
		free(new_line);
		exit(EXIT_FAILURE);
	}
	
	linii = p;
	linii[n_linii] = new_line;
	n_linii++;
}


int aparitii(char *line, char *word)
{
		int contor = 0;
		int len = strlen(word);
		
		char *pointer = strstr(line, word);
		
		while(pointer != NULL)
		{
			contor++;
			line = pointer + len;
			pointer = strstr(line, word);
		}
	
	return contor;
}

int main(void)
{

	char linie[1000];
	char word[]="mere";
	int contor = 0;

	if((f = fopen("test.txt", "r"))==NULL)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	
	while(fgets(linie, 1000, f) != NULL)
	{
		adauga(linie);
	}
	
	fclose(f);
	
	FILE *f2=NULL;
	
	if((f2 = fopen("out.txt", "w"))==NULL)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	
	
	for(int i=0; i<n_linii; i++)
		contor = contor + aparitii(linii[i], word);
	
	fprintf(f2, "%s apare de %d ori ", word, contor);
	fclose(f2);
	eliberare();

}

Se consideră un fișier text ce conține in general text, de o dimensiune necunoscută, programul considerând-o infinită. Să se scrie un program care citește acest fișier și scrie în fișierul histo.txt histragama literelor din fișier. Prin histrograma literelor (mari și mici) se înțelege distribuția în procente a acestora, procentul de apariție din total. În fișierul histo.txt se vor scrie linii sub forma : litera - numar apariții.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

FILE *f = NULL;
int ap[30]={0};

int main(void)
{
	if((f = fopen("test.txt", "r")) == NULL)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	
	char ch; int total=0;
	
	while((ch = fgetc(f)) != EOF)
	{
		if(isalpha(ch))
		{
		int index = (int)tolower(ch) - 96;
		ap[index]++;
		total++;
		}
	}
	fclose(f);
	char litera = 'a';
	
	for(int i=1; i<26; i++, litera++)
	{
	printf("%c - %.2g%%\n", litera, (double)(ap[i]*100/(double)total));
	}

}



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char linie[1000];

typedef struct
{
char *nume;
double media;
}data;

data *elev;
int n=0;
	
int main()
{
	FILE *f = NULL;
	
	if((f = fopen("test.txt", "r"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	while(fgets(linie, 1000, f)!=NULL)
	{
	
		if((elev = (data*)realloc(elev, sizeof(data)*(n+1)))==NULL)
		{
			perror(NULL);
			exit(-1);
		}
		char *p = strtok(linie, " ");
		char *nume_elev, *prenume_elev;
		if((nume_elev = (char*)malloc(sizeof(char)*(strlen(p)+1)))==NULL)
			{
			perror(NULL);
			exit(-1);
			}
		strcpy(nume_elev, p);
		p = strtok(NULL, " ");
		if((prenume_elev = (char*)malloc(sizeof(char)*(strlen(p)+1)))==NULL)
			{
			perror(NULL);
			exit(-1);
			}
		strcpy(prenume_elev, p);
		if((elev[n].nume = (char*)malloc(sizeof(char)*(strlen(nume_elev)+strlen(prenume_elev)+1)))==NULL)
		{
			perror(NULL);
			exit(-1);
		}
		strcat(elev[n].nume, nume_elev);
		strcat(elev[n].nume, " ");
		strcat(elev[n].nume, prenume_elev);
		
		double suma = 0, contor=0;
		
		while(p!=NULL)
		{
			
			suma = suma + atof(p);
			contor++;
			
			p = strtok(NULL, " ");
			
		}
		
		elev[n].media = suma/(contor-1);
		
		printf("%s - %.3g\n", elev[n].nume, elev[n].media);
		
		n++;
		
		free(nume_elev);
		free(prenume_elev);
	}
	
	fclose(f);
	
	
	for(int i=0; i<n; i++)
		{
		free(elev[i].nume);
		}
	free(elev);
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char linie[500];
int n=0;

typedef struct{
	char *nume;
	double pret;
}data;

data *prod;

void  eliberare()
{
	for(int i=0; i<n; i++)
		free(prod[i].nume);
	free(prod);
}

void cautare(const char *name)
{
	for(int i=0; i<n; i++)
		if(strcmp(prod[i].nume, name)==0)
			printf("%.3g\n", prod[i].pret);
}

int main(void)
{
	FILE *f = NULL;
	
	if((f = fopen("test.txt", "r"))==NULL)
	{
	perror(NULL);
	exit(-1);
	}
	
	while(fgets(linie, 500, f)!=NULL)
	{
		if((prod = (data*)realloc(prod, sizeof(data)*(n+1)))==NULL)
		{
			perror(NULL);
			exit(-1);
		}
		
		char *p = strtok(linie, " ");
		
		if((prod[n].nume = (char*)malloc(sizeof(char)*(strlen(p)+1)))==NULL)
		{
			perror(NULL);
			exit(-1);
		}
		strcpy(prod[n].nume, p);
		
		p = strtok(NULL, " ");
		
		prod[n].pret = atof(p);
		
		n++;
	
	}
	
	fclose(f);
	
	cautare("Domestos");
	
	eliberare();
	
	
} 


#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char **linii;
int n_linii=0;
int n;

typedef struct
{
char *nume;
double salariu;
}data;

data *angajat=NULL;

void adauga_linie(char *linie)
{
	char *linieNoua = NULL;
	
	if((linieNoua = (char*)malloc(sizeof(char)*(strlen(linie)+1)))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(linieNoua, linie);
	char **p = NULL;
	
	if((p = (char**)realloc(linii, sizeof(char*)*(n_linii+1))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	linii = p;
	linii[n_linii]=linieNoua;
	n_linii++;
}

int main(void)
{
	char linie[1000];
	
	FILE *f = NULL;
	
	if((f = fopen("test.txt", "r"))==NULL)
		{
		perror(NULL);
		exit(-1);
		}
		
	while(fgets(linie, 1000, f)!=NULL)
	{
	
		if((angajat = (data*)realloc(angajat,sizeof(data)*(n+1)))==NULL)
		{
			perror(NULL);
			exit(-1);
		}
		adauga_linie(linie);
		char *p = NULL;
		p = strtok(linie, ",");
		if((angajat[n].nume = (char*)malloc(sizeof(char)*(strlen(p)+1)))==NULL)
			{
			perror(NULL);
			exit(-1);
			}
		strcpy(angajat[n].nume, p);
		p=strtok(NULL, ",");
		angajat[n].salariu = atof(p);
		n++;
	}
	
	fclose(f);
	
	FILE *f2 = NULL;
	
	if((f2 = fopen("out.txt", "w"))==NULL)
		{
		perror(NULL);
		exit(-1);
		}
		
	for(int i=0; i<n; i++)
		fprintf(f2, "%s - %g\n", angajat[i].nume, angajat[i].salariu);
	
	fclose(f2);
	for (int i = 0; i < n_linii; i++)
        	free(linii[i]);
    	free(linii);
	
	for(int i=0; i<n; i++)
		free(angajat[i].nume);
	free(angajat);
	
}


/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct
{
char *cuvant;
int contor;
}data;

data *ap;
int n=0;

int cautare(char *where, char *what)
{
	char *haystack = strstr(where, what);
	int len=strlen(what), contor=0;
	
	while(haystack)
	{
	contor++;
	where = haystack + len;
	haystack = strstr(where, what);
	}
	
	return contor;
}

void lower(char *chestie)
{
	int len = strlen(chestie);
	
	for(int i=0; i<len; i++)
		chestie[i]=tolower(chestie[i]);		
}

int main()
{
	char linie[1000]="ANA aRE mEre";
	
	FILE *f = NULL;
	
	if((f = fopen("test.txt", "r"))==NULL)
		{
		perror(NULL);
		exit(-1);
		}
		
	while(fgets(linie, 1000, f)!=NULL)
	{
	if((ap = (data*)realloc(ap, sizeof(data)*(n+1)))==NULL)
		{
		perror(NULL);
		exit(-1);
		}
	
	lower(linie);
	char *l_noua;
	
	if((l_noua = (char*)malloc(sizeof(char)*(strlen(linie)+1)))==NULL)
		{
		perror(NULL);
		exit(-1);
		}
	strcpy(l_noua, linie);
	
	char *p=strtok(l_noua, " ");
	while(p!=NULL)
	{
		char *cuv; int indice;
		if((cuv = (char*)malloc(sizeof(char)*(strlen(p)+1)))==NULL)
		{
			perror(NULL);
			exit(-1);
		}
		strcpy(cuv, p);
		lower(cuv);
		int ok=0;
		int c = cautare(linie, cuv);
		
		for(int i=0; i<n; i++)
			if(strcmp(cuv, ap[i].cuvant)==0)
				{
				ok=1;
				indice = i;
				}
		if(ok!=0)
			ap[indice].contor = ap[indice].contor+c;
		else
		{
	
			if((ap[n].cuvant = (char*)malloc(sizeof(char)*(strlen(cuv)+1))) == NULL)
				{
				perror(NULL);
				exit(-1);
				}
			strcpy(ap[n].cuvant, cuv);
			ap[n].contor = c;
			n++;
		}
		p = strtok(NULL, " ");
	}
	
	}
	fclose(f);
	
	
	for(int i=0; i<n; i++)
		printf("%s - %d\n", ap[i].cuvant, ap[i].contor);
		
	for(int i=0; i<n; i++)
		free(ap[i].cuvant);
	free(ap);

		
}
*/










