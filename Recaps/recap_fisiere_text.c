#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

//LABORATOR 13 CV: Fisiere Text
/*


typedef struct
{
char titlu[35];
int an;
int buget;
}Data;

Data *film = NULL;

int main(void)
{
	FILE *f= NULL;
	char linie[1000];
	
	if((f = fopen("movies.csv", "r")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	int len = MAX, index=0;
	
	if((film = malloc(sizeof(Data)*MAX))==NULL)
	{
		perror("Memorie insuficienta!");
		exit(-1);
	}
	//citim capul de tabel
	fgets(linie, 1000, f);
	
	while(fgets(linie, 1000, f)!=NULL)
	{
		int poz=0;
		
		if(index == len)
		{
		len = len + MAX;
		if((film = realloc(film, sizeof(Data)*len))==NULL)
		{
			perror(NULL);
			exit(-1);
		}
		}
		
		char *p=NULL;
		p = strtok(linie, ",");

		while(p)
		{
			if(poz == 0)
				film[index].an = atoi(p);
			if(poz == 2)
				strcpy(film[index].titlu, p);
			if(poz == 6)
				film[index].buget = atoi(p);
			poz++;
			p = strtok(NULL , ",");
		}
		
		index++;
	}
	
	fclose(f);
	
	if((film = realloc(film, sizeof(Data)*index))==NULL)
		{
			perror(NULL);
			exit(-1);
		}
	len = index;
	
	FILE *g = NULL;
	
	if((g = fopen("test.txt", "w")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	for(int i=0; i<len; i++)
		fprintf(g, "%s %d %d\n", film[i].titlu, film[i].an, film[i].buget);
		
	free(film);
	fclose(g);
}


//Problema 2
int main(void)
{
	FILE *f=NULL;
	FILE *out = NULL;
	float value;
	float *v = NULL; 
	int len = MAX, index=0;
	
	if((f = fopen("numbers.txt", "r")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	if((v = malloc(sizeof(float)*len))==NULL)
	{
		perror("Memorie insuficienta");
		exit(-1);
	}
	
	while(1)
	{
		fscanf(f, "%g", &value);
		
		if(value!=0)
		{
			*(v + index) = value;
			index++;
			
			if(index == len)
			{
			len = len + MAX;
			
			if((v = realloc(v, sizeof(float) * len))==NULL)
			{
				perror("Memorie insuficienta");
				exit(-1);
			}
			
			}
		}
		else
		{
			break;
		}
	}
	fclose(f);
	
	if((v = realloc(v, sizeof(float) * index))==NULL)
			{
				perror("Memorie insuficienta");
				exit(-1);
			}
	len = index;
	
	if((out = fopen("test.txt", "w")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	for(int i=0; i<len; i++)
		fprintf(out, "%g | ", *(v+i));
	fclose(out);
	free(v);
	
}

//PROBLEMA 3
typedef struct
{
char judet[100];
int beneficiari;
int suma;
}Data;

Data *v = NULL;

int main(void)
{
	FILE *src = NULL;
	FILE *out = NULL;
	int len=MAX, index=0, pop_max=0, sum_max=0;
	char linie[1000];
	
	if((src = fopen("indemnizatie.csv", "r")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	if((v = malloc(sizeof(Data) * len)) == NULL)
	{
		perror("Memorie insuficienta1");
		exit(-1);
	}
	
	fgets(linie, 1000, src);
	
	while(fgets(linie, 1000, src)!=NULL)
	{
		if(index == len)
		{
		len = len + MAX;
		
		if((v = realloc(v, sizeof(Data)*len))==NULL)
		{
			perror("Memorie insuficienta2");
			exit(-1);
		}
		}
		int poz=0;
		char *p = strtok(linie, ";");
		while(p)
		{
			if(poz == 0)
				strcpy(v[index].judet, p);
			if(poz == 1)
			{
				int pop;
				pop = atoi(p);
				if(pop>pop_max)
					pop_max = pop;
			}
			if(poz == 2)
			{
				v[index].beneficiari = atoi(p);
			}
			if(poz == 4)
			{
				v[index].suma = atoi(p);
			}
			if(poz == 5)
			{
				int sum = atoi(p);
				if(sum>sum_max)
					sum_max = sum;
			}
			poz++;
			p = strtok(NULL, ";");
		}
		index++;
	}
	fclose(src);
	
	if((v = realloc(v, sizeof(Data) * index))==NULL)
			{
				perror("Memorie insuficienta3");
				exit(-1);
			}
	len = index;
	
	if((out = fopen("test.txt", "w")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	for(int i=0; i<index; i++)
		fprintf(out, "%s - %d - %d\n", v[i].judet, v[i].beneficiari, v[i].suma);
	fclose(out);
	free(v);
}
*/

#define CHUNK 10
#define ARRAY_CHUNK 2

#define ARRAY_SIZE 10


char *get_line(FILE *f)
{
	char *line = NULL;
	char ch;
	int index=0;
	int current_size= 0; //dimensiunea curenta
	
	while((ch = fgetc(f))!=EOF)
	{
		if(index == current_size)
		{
			current_size += CHUNK;
			if((line = realloc(line, sizeof(char) * current_size))==NULL)
			{
				perror(NULL);
				exit(-1);
			}
		}
		
		if(ch != '\n')
		{
			*(line + index) = ch;
			index++;
		}
		else
		{
		break;
		}	
	 }
	//trebuie sa adaug terminatorul de string \0
	if(line != NULL)
		{
			if(index == current_size) //daca nu am spatiu de memorie, imi fac
			{
			current_size++;
			if((line = realloc(line, sizeof(char) * current_size))==NULL)
				{
					perror(NULL);
					exit(-1);
				}
			}
			
			*(line + index) = 0; //terminatorul de sir 
		
		}
	return line;
}

char **get_lines(FILE *f)
{
	char **lines = NULL;
	char *current_line = NULL;
	int i=0, current_size=0;
	
	while((current_line = get_line(f)) != NULL)
	{
		if(i == current_size)
		{
		current_size += ARRAY_CHUNK;
			if((lines = realloc(lines, current_size * sizeof(char*)))==NULL)
			{
				perror(NULL);
				exit(-1);
			}
		}
		lines[i] = current_line;
		i++;
	}
	
	if( i == current_size )
	{
		current_size++;
		if((lines = realloc(lines, current_size * sizeof(char*)))==NULL)
			{
				perror(NULL);
				exit(-1);
			}
	}
	lines[i] = NULL;
	return lines;
}


void print_lines(char **lines)
{
	char **p; //variabila intermediara pt parcurgerea tabloului de pointeri
	int i=0;
	p = lines;
	
	FILE *out = NULL;
	
	if((out = fopen("test.txt", "w"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	while(*p != NULL)
	{
	fprintf(out, "%d - %s\n", i, *p);
	p++; //trecem la urmatoarea linie
	i++;
	}
	fclose(out);
}

void free_lines(char **lines)
{
	char **p; //variabila intermediara
	p = lines;
	
	while(*p != NULL)
	{
	free(*p);
	p++;
	}
}

int main(void)
{
	char **lines = NULL;
	FILE *f = NULL;
	
	if((f = fopen("scrisoare.txt", "r"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	lines = get_lines(f);
	fclose(f);
	print_lines(lines);
	free_lines(lines);

	free(lines);
}










































