/*1.) Să se scrie o funcție care primește două șiruri de caractere și le concatenează cu un spațiu între ele, folosind un bloc de memorie alocat dinamic pentru rezultat. Funcția va returna acest bloc de memorie. Să se verifice funcția cu două șiruri de caractere introduse de la tastatură, fiecare de maxim 100 de caractere.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *concatenare(char s1[], char s2[])
{
	char *p=NULL;
	p = (char*)malloc((strlen(s1)+strlen(s2))*sizeof(char));
	strcat(p,s1);
	strcat(p, " ");
	strcat(p, s2);
	return p;
}

int main(void)
{
char s1[101], s2[101];
char *p = NULL;

scanf("%3s", s1);
scanf("%4s", s2);

p = concatenare(s1,s2);
printf("%s", p);
free(p);

}

2.) Se citesc numere până la întâlnirea numărului 0. Să se afișeze aceste numere în ordine inversă.

#include<stdio.h>
#include<stdlib.h>

#define CHUNK 20

void read_array_din(int v[], int *size)
{
	int aux, index=0;
	int current_size=CHUNK;
	
	if((v=malloc(current_size * sizeof(int)))==NULL)
	{
		printf("Memorie insuficienta");
		exit(1);
	}
	
	while(1)
	{
		scanf("%d", &aux);
		if(aux==0)
			break;
		else
		{
		v[index]=aux;
		index++;
		
		if(index == current_size)
		{
		current_size = current_size + CHUNK;
		
		if((v = realloc(v, current_size * sizeof(int)))==NULL)
			{
				printf("CACA");
				exit(-1);
			}
		}
		}
	}
	if((v = realloc(v, index * sizeof(int)))==NULL)
			{
				printf("CACA");
				exit(-1);
			}
	*size = index;
	
	for(int i=*size-1; i>=0; i--)
		printf("%d ", v[i]);
	
	free(v);
}

int main(void)
{
	int v[1000], size=0;
	read_array_din(v, &size);
} 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
	char cuv[20], *p=NULL;
	int c=1;
	
	while(scanf("%s", cuv)!=EOF)
	{
		if(c==1)
		{
			if((p=malloc(strlen(cuv)*sizeof(char)))==NULL)
			{
			printf("Eroare");
			exit(-1);
			}
			
			strcpy(p,cuv);
			c++;
		}
		else
		{
			if(tolower(cuv[0])==tolower(p[strlen(p)-2]) && tolower(cuv[1])==tolower(p[strlen(p)-1]))
			{
			if((p = realloc(p, (strlen(p)+strlen(cuv)+2)*sizeof(char)))==NULL)
			{
			printf("Eroare");
			exit(-1);
			}
			strcat(p, "-");
			strcat(p, cuv);
			}
		}
	}
	
	printf("%s", p);
	free(p);
	
}


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *string_replace_dynamic(const char *where, const char *what, const char *replace)
{
	char *p=NULL, *t=NULL;
	int n, m, poz=0;
	n=strlen(where); //n e ca sa stim cu ce dimensiune sa realocam
	if((p=malloc((n+1)*sizeof(char)))==NULL)
	{
	printf("ERROR");
	exit(-1);
	}
	else
	{
	t = strstr(where, what);
	do{
	m = strlen(where+poz) - strlen(t);
	strncat(p, where+poz, m);
	n = n + strlen(replace);
	
	if((p = realloc(p, (n+1)*sizeof(char)))==NULL)
	{
	printf("ERROR");
	exit(-1);
	}
	strcat(p,replace);
	poz = poz + m + strlen(what);
	t = strstr(where+poz, what);
	}while(t!=NULL);
	
	strncat(p, where+poz, strlen(where+poz));
	return p;
	}
}

int main(void)
{
	char s1[]="Acesta este un string si un string este terminat cu 0x00";
	char s2[]="string";
	char s3[]="sir de caractere";
	char *p=NULL;
	p = string_replace_dynamic(s1, s2, s3);
	printf("%s", p);
	free(p);
	return 0;
}


//problema 5
#include<stdio.h>
#include<stdlib.h>

#define CHUNK 100

void read_sort_array(int v[], int *size)
{
	int index = 0, aux;
	int current_size = CHUNK;
	if((v=malloc(current_size * sizeof(int)))==NULL)
	{
		printf("ERROR");
		exit(-1);
	}
	
	while(scanf("%d", &aux)!=EOF)
	{
		v[index]=aux;
		index++;
		
		if(index == current_size)
		{
			current_size = current_size + CHUNK;
			if((v=realloc(v, current_size*sizeof(int)))==NULL)
			{
				printf("ERROR");
				exit(-1);
			}
		}
	}
	
	if((v=realloc(v, index*sizeof(int)))==NULL)
	{
		printf("ERROR");
		exit(-1);
	}
	*size = index;
	
	for(int i=0; i<*size-1; i++)
	   for(int j=i+1; j<*size; j++)
	   	if(v[i]<v[j])
	   	{
	   	aux=v[i];
	   	v[i]=v[j];
	   	v[j]=aux;
	   	}
	   	
	for(int i=0; i<*size; i++) 
		printf("%d ", v[i]);
		
	free(v);
		
}

int main(void)
{
	int v[100], n=0;
	read_sort_array(v, &n);
	
}

//pb6
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char *text2hex(const char *string)
{
	char *p, aux[3];
	p = malloc((strlen(string)*2+1)*sizeof(char));
	
	sprintf(p,"%02X", string[0]);
	
	for(int i=1; i<strlen(string); i++)
	{
		sprintf(aux, "%02X", string[i]);
		strcat(p, aux);
	}
	return p;
}

int main(void)
{
 char s[]="abjabc";
 char *p = text2hex(s);
 printf("%s", p);
 free(p);
}
*/

//pb7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int hexx(char *hex)
{
    int decimal;
    sscanf(hex,"%2X",&decimal);
    return decimal;
}
char *hex2text(const char *string)
{
    char *p;
    p=(char*)malloc((strlen(string)/2+1)*sizeof(char));
    char aux[10],aux2[10];
    if(p==NULL)
    {
        printf("eroare\\");
        return NULL;
    }
    for(int i=0;i<strlen(string);i=i+2)
    {
        aux2[0]=string[i];
        aux2[1]=string[i+1];
        aux[0]=hexx(aux2);
        if(i==0)
        strcpy(p,aux);
        else
        strcat(p,aux);
    }
    return p;
}
int main(void)
{
    char d[1500],*p;
    scanf("%s",d);
    p=hex2text(d);
    printf("%s",p);
    return 0;
}













