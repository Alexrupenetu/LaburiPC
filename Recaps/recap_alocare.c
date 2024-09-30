#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<ctype.h>

#define MAX 5

//LABORATOR 12 CV: ALOCARE DINAMICA

//1.)Să se scrie o funcție care primește două șiruri de caractere și le concatenează cu un spațiu între ele, folosind un bloc de memorie alocat dinamic pentru rezultat. Funcția va returna acest bloc de memorie. Să se verifice funcția cu două șiruri de caractere introduse de la tastatură, fiecare de maxim 100 de caractere.
char* concatenare(char *s1, char *s2)
{
	char *new_string = NULL;
	int len;
	len = strlen(s1) + strlen(s2) + 5;
	new_string = (char*)malloc(sizeof(char) * len);
	strcpy(new_string, s1);
	strcat(new_string, " ");
	strcat(new_string, s2);
	
	return new_string;
}

//2.)Se citesc numere până la întâlnirea numărului 0. Să se afișeze aceste numere în ordine inversă. Programul va folosi doar minimul necesar de memorie

void p2()
{
	int value, index=0, len=MAX;
	char *v=NULL;

	if((v = malloc(sizeof(int) * len))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	while(1)
	{
		scanf("%d", &value);
		
		if(value!=0)
		{
			*(v+index) = value;
			index++;
			
			if(index == len)
			{
			len = len + MAX;
			if((v = realloc(v, sizeof(int) * len))==NULL)
			{
			perror(NULL);
			exit(-1);
			}
			
			}
		}
		else
		{
		break;
		}
	}
	
	len = index;
	
	if((v = realloc(v, sizeof(int) * len))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	for(int i=0; i<len; i++)
	 printf("%d ", *(v + i));
	
	printf("\n"); 
	free(v);
	
}

//3.) Problema cu Fazan
void p3()
{
	char cuv[25], *fazan = NULL;
	int len;
	
	scanf("%s", cuv);
	getchar();
	if((fazan = malloc(sizeof(char)*(strlen(cuv)+2)))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(fazan, cuv);
	
	while(scanf("%s", cuv)!=EOF)
	{
		len = strlen(fazan);
		
		if((tolower(fazan[len-2]) == tolower(cuv[0])) && (tolower(fazan[len-1]) == tolower(cuv[1])))
		{
			if((fazan = realloc(fazan, sizeof(char) * (len + strlen(cuv) + 2))) == NULL)
			{
				perror(NULL);
				exit(-1);
			}
			
			strcat(fazan, "-");
			strcat(fazan, cuv);
		
		}
	}
	
	printf("%s", fazan);
	free(fazan);
}

//4.)  Nu da asa ceva (speram)

//5.) Se va citi de la intrarea standard un numar neconscut de valor intregi nenule pozitive pana la EOF. Se vor stoca aceste elemente intr-un tablou dinamic. Programul va afisa la iesirea standard tabloul sortat descrescator.

void p5()
{
	int value,index=0, len=MAX;
	int *v=NULL;
	
	if((v = malloc(sizeof(int)*len))==NULL)
	{
	perror(NULL);
	exit(-1);
	}
	
	while(scanf("%d", &value)!=EOF)
	{
		*(v+index) = value;
		index++;
		
		
		if(index == len)
		{
			len = len + MAX;
			
			if((v = realloc(v, sizeof(int) * len))==NULL)
			{
				perror(NULL);
				exit(-1);
			}
		}
	}
	
	if((v = realloc(v, sizeof(int) * index))==NULL)
			{
				perror(NULL);
				exit(-1);
			}
	len = index;
	
	for(int i=0; i<len; i++)
		printf("%d ", *(v+i));
	free(v);

}

/*6.)    Să se scrie o funcție care primește ca argument un string și returnează un alt string alocat dinamic în care fiecare caracter din string-ul inițial va fi înlocuit cu valoarea în hexazecimal a caracterului conform tabelei ASCII în format text pe strict două cifre hexazecimale fără prefixul 0x. Antetul funcției poate fi următorul

char *text2hex(const char *string);

Exemplu: string = "abc" -> funcția va returna un string de forma "616263" */

void p6()
{
	char *p, aux[3], string[100];
	
	scanf("%s", string);
	
	if((p = malloc(sizeof(char) * (2*strlen(string) + 2)))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	sprintf(p, "%02x", string[0]);
	
	for(int i=1; i<strlen(string); i++)
	{
		sprintf(aux, "%02X", string[i]);
		strcat(p,aux);
	}
	
	printf("%s", p);
	free(p);
	
}

/*
    Să se scrie o funcție care primește ca argument un string ce conține în format text valori în hexazecimal pe două cifre hexazecimale fără prefixul 0x. Aceste valori reprezintă caractere conform tabelei ASCII. Funcția va decodifica textul și il va returna într-un string alocat dinamic. Antetul funcției poate fi următorul:
    
char *hex2text(const char *hexstring);

Exemplu: hexstring = "616263" -> funcția va returna string-ul "abc"

void p7()
{
	char *p=NULL;
	char aux[3], AUX[3], string[100];
	
	scanf("%s", string);
	
	int len = strlen(string);
	
	if((p = malloc(sizeof(char) * len))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	for(int i=0; i<len; i=i+2)
	{
		aux[0] = string[i];
		aux[1] = string[i+1];
	}
}*/

//8.) Translatare in pasareasca

void p8()
{
	char string[100], *p=NULL, litera[2];
	
	fgets(string, 100, stdin);
	
	if((p = malloc(sizeof(char)*(3*strlen(string)+2))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	for(int i=0; i<strlen(string); i++)
	{
		litera[0] = string[i];
		litera[1] = '\0';  //adaug terminatorul de sir pt a forma un sir valid
		if(i==0)
			{
			sprintf(p, "%c", string[0]);
				if(strstr("aeiou", litera)!=0)
			{
				strcat(p, "p");
				strcat(p, litera);
			}
			}
		else
		{
		strcat(p, litera);	
		if(strstr("aeiou", litera)!=0)
		{
			strcat(p, "p");
			strcat(p, litera);
		}
		}
	}
	printf("%s", p);
	free(p);
}

int main(void)
{	
	/*char *new_string=NULL;
	new_string = concatenare("ana", "are mere");
	printf("%s", new_string);
	free(new_string);*/
	p8();
}





















