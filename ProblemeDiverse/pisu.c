/*Cititi linii dintr un fisier. Prelucrati fiecare linie ai literele mari sa devina litere mici si invers.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//CITIM MAI MULTE LINII DE DIMENSIUNE 1000 DINTR UN FISIER 

char **linii;
char linie[1000];
int n_linii;

void eliberare()
{
	for(int i=0; i<n_linii; i++)
		free(linii[i]);
	free(linii);
}


void schimba_litere(char *linie)
{
	int len = strlen(linie);
	
	for(int i=0; i<len; i++)
	{
		char c = linie[i];
		if(c>='A' && c<='Z')
			c = tolower(c);
		else if(c>='a' && c<='z')
			c = toupper(c);
			
		linie[i]=c;
	}
}

void capitalizare_litera_cuv(char *linie)
{
	char c;
	c = linie[0];
	linie[0] = toupper(c);
	
	for(int i=2; i<strlen(linie); i++)
		if(linie[i-1]==' ')
			{
				c = linie[i];
				linie[i] = toupper(c);
			}

}

int cautare_cuvant(char *where, char * what)
{
	char *haystack = strstr(where, what);
	int len = strlen(what);
	int contor =0;
	
	while(haystack!=NULL)
	{
		contor++;
		where = haystack +  len;
		haystack = strstr(where, what);
	}
	
	return contor;
}

void upper_substring(char * where, char *what)
{
	char *haystack = NULL;
	int len = strlen(what);
	
	haystack = strstr(where, what);
	
	while(haystack!=NULL)
	{
		
		for(int i=0; i<len; i++)
		{
		*haystack = toupper(*haystack);
		haystack++;
		}
		haystack = strstr(where, what);
	}
	
	printf("%s", where);
}

void upper_substring_dyn(char *where, char *what)
{
	int len = strlen(what);
	char *haystack = where;
	
	char *result=NULL;
	
	if((result = (char*)malloc(strlen(where)+1))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	strcpy(result, where);
	
	haystack = strstr(result, what);
	
	while(haystack != NULL)
	{
		for(int i=0; i<len; i++)
			result[haystack - result +i] = toupper(result[haystack - result +i]);
			
		if((result = (char*) realloc(result, sizeof(char)*(strlen(result)+len+1))) == NULL)
		{
			perror(NULL);
			exit(-1);
		}
		
		haystack = strstr(haystack+len, what);
	}
	
	printf("%s\n", result);
}

void adauga_linie(char *linie)
{
	char *linieNoua;
	
	if((linieNoua = (char*)malloc(sizeof(char)*(strlen(linie)+1))) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	capitalizare_litera_cuv(linie);
	strcpy(linieNoua, linie);
	
	char **p=NULL;
	
	if((p = (char**)realloc(linii, sizeof(char*)*(n_linii+1)))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	linii = p;
	linii[n_linii] = linieNoua;
	n_linii++;
}

int main()
{
	/*FILE *f = NULL;
	
	if((f = fopen("test.txt", "r")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	while(fgets(linie, 1000, f) != NULL)
	{
		adauga_linie(linie);
	}
	
	fclose(f);
	
	for(int i=0; i<n_linii; i++)
		printf("%s", linii[i]);
		
	eliberare();*/
	
	char linie[500]="pustoaica cu par roscat in grea boala roscat m ai bagat";
	char cuv[20]="roscat";
	
	upper_substring_dyn("pustoaica cu par roscat in grea boala roscat m ai bagat", "roscat");
	
}




