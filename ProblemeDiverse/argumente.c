#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void afisare_fisier(char *pathname)
{
	FILE *f;
	
	if((f = fopen(pathname, "r"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	char ch;
	
	while((ch = fgetc(f))!=EOF)
		printf("%c", ch);
		
	fclose(f);	
	printf("\n");
}

void afisare_u_fisier(char *pathname)
{
	FILE *f;
	
	if((f = fopen(pathname, "r"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	char ch;
	
	while((ch = fgetc(f))!=EOF)
		{
		if(isalpha(ch))
			ch = toupper(ch);
		printf("%c", ch);
		}
	fclose(f);	
	printf("\n");
}

void afisare_l_fisier(char *pathname)
{
	FILE *f;
	
	if((f = fopen(pathname, "r"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	char ch;
	
	while((ch = fgetc(f))!=EOF)
		{
		if(isalpha(ch))
			ch = tolower(ch);
		printf("%c", ch);
		}
	fclose(f);	
	printf("\n");
}


int main(int argc, char **argv)
{
	afisare_fisier(argv[1]);
	for(int i=2; i<argc; i++) //pornim de la 1 fiindca argv[0] este "./p"
		{
			if(strstr(argv[i], "-u"))
				{
					afisare_u_fisier(argv[i+1]);
					i++;
				}
			if(strstr(argv[i], "-l"))
				{
					afisare_l_fisier(argv[i+1]);
					i++;
				}
			if(strstr(argv[i], "-o"))
				{
					afisare_fisier(argv[i+1]);
					i++;
				}
		}
}
