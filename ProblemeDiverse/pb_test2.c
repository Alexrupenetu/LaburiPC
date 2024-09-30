#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
/*Se citesc 2 vectori pe 32 de biti A si B dintr-un fisier pana la EOF. Sa se realizeze o functie de citire din fisier cu 3 parametri(vectorul A, vectorul B, dimensiunea comuna). Apoi, toate numerele din vectorul A care au paritate para pe biti (adica daca au un nr par de biti de 1) sa fie adaugate la vectorul B, avand grija sa nu fie depasita memoria, iar la final sa se afiseze vectorul B.

void citire(uint32_t *A, uint32_t *B, int dim)
{	
	uint32_t value;
	int index = 0;
	
	while(scanf("%d", &value)!=EOF)
	{
		if(index<dim)
		{
		A[index] = value;
		index++;
		}
		else if(index<2*dim && index>=dim)
		{
		B[index-dim] = value;
		index++;
		}
		else
		{
		printf("Memorie insuficienta!");
		break;
		}
	}
}

int paritate_bitz(uint32_t n)
{
	int contor=0;
	uint32_t mask = 1;
	
	for(int i=31; i>=0; i--)
		if(((n & (mask<<i))>>i) == 1)
			contor++;
	if(contor%2 == 0)
		return 1;
	else
		return 0;
}

void adaugare(uint32_t *A, uint32_t *B, int dim, int *new_dim)
{
	*new_dim = dim;
	for(int i=0; i<dim; i++)
		if(paritate_bitz(A[i]) == 1)
			{
			B[*new_dim] = A[i];
			*new_dim = *new_dim + 1;
			}
}

void afisare(uint32_t *A, uint32_t *B, int dim, int new_dim)
{
	printf("\n");
	for(int i=0; i<dim; i++)
		printf("%d ", A[i]);
	printf("\n");
	for(int i=0; i<new_dim; i++)
		printf("%d ", B[i]);
	printf("\n");
}

int main()
{
	uint32_t A[MAX], B[MAX];
	int dim = 4, new_dim;
	citire(A, B, dim);
	adaugare(A, B, dim, &new_dim);
	afisare(A, B, dim, new_dim);
}

Se citeste un vector de numere intregi fara semn pe 16 biti de dimensiune nedefinita,si se formeaza un numar intreg fara semn pe 32 biti care are pe cei mai semnificativi 16 biti cel mai mare numar impar din vector,iar pe restul 16,pozitia din vector la care se gaseste cel mai mare numar impar.Rezolvarea se face folosind doar pointeri(fara indecsi).Se trateaza situatiile in care dimensiunea vectorului este prea mare.(se stabilieste o limita).


uint16_t *citire(FILE *f, char *stream, int *len)
{
	uint16_t *v = NULL; uint16_t value;
	int index = 0;
	*len = 0; 
	
	if((f = fopen(stream, "r"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	while(fscanf(f, "%hu", &value)!=EOF)
	{
	
		if(index == *len)
		{
			*len += MAX;
			if((v = realloc(v, sizeof(uint16_t) * (*len))) == NULL)
			{
				perror("Mem insuf!");
				exit(-1);
			}
		}
		v[index] = value;
		index++;
	}
	fclose(f);
	if((v = realloc(v, sizeof(uint16_t) * index)) == NULL)
			{
				perror("Mem insuf!");
				exit(-1);
			}
	*len = index;
	return v;
	
}

uint16_t cmi(uint16_t *v, int dim)
{
	uint16_t impar = 0;
	for(int i=0; i<dim; i++)
		if(*(v+i)%2==1 && *(v+i)>impar)
			 impar = *(v+i);
	return impar;
}

uint16_t pozitie(uint16_t *v, uint16_t impar, int dim)
{
	uint16_t poz;
	for(int i=0; i<dim; i++)
		if(*(v+i) == impar)
			poz = i;
	return poz;
}

uint32_t create_32(uint32_t n1, uint32_t n2)
{
	//n1 n2
	uint32_t new = 0;
	new |= (n1<<16) | n2;
	return new;
}

void show_32(uint32_t n)
{
	uint32_t mask = 1;
	
	for(int i=31; i>=0; i--)
		printf("%d", ((n &(mask<<i))>>i));
	printf("\n");
}

int main()
{
	uint16_t *v=NULL;
	uint16_t impar, poz; uint32_t rez;
	int dim=0;
	FILE *f = NULL;
	v = citire(f, "test.txt", &dim);
	impar = cmi(v,dim);
	poz = pozitie(v, impar, dim);
	printf("%hu - %hu\n", impar, poz);
	rez = create_32(impar, poz);
	show_32(rez);
	free(v);
	
}



char *modificare(char *s)
{
	char  *new_s=NULL, aux[7]="";
	int len = strlen(s), contor=0;
	
	//parcurgem si numaram cate spatii are sa vedem cata memorie alocam pt noul string
	for(int i=0; i<len; i++)
	{
		if(isalpha(s[i])==0)
			contor++;
	}
	
	if((new_s = malloc(sizeof(char)*(len + 5*contor + 1))) == NULL)
	{
		perror("Memorie Insuficienta");
		exit(-1);
	}
	
	int index = 0;
	
	for(int i=0; i<len; i++)
	{
		if(isalpha(s[i]))
			{
				new_s[index] = s[i];
				index++;
			}
		else
		{
		sprintf(aux, "[0x%x]", s[i]);
		strcat(new_s, aux);
		index += 6;
		}
	}
	
	return new_s;
}

int main(void)
{
	char s[200], *rez = NULL;
	
	if(fgets(s, 200, stdin)!=NULL)
	{
		if(s[strlen(s)-1]=='\n')
			s[strlen(s)-1] = '\0'; //adaugam terminatorul de sir
		rez = modificare(s);
	}
	
	printf("%s\n", rez);
	free(rez);
	return 0;
}

#define CHUNKY 10

char *read(FILE *f, char *stream)
{
	if((f = fopen(stream, "r"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	char *s = NULL, temp[CHUNKY];
	int contor = 2;
	
	if((s = malloc(sizeof(char)*CHUNKY))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	s[0]=0; //sa fie practic sirul vid;
	
	while(fgets(temp, CHUNKY, f)!=NULL)
	{
		s = strcat(s, temp);
		
		if(strlen(temp) < CHUNKY-1)
			break;
		else
		{
			if((s = realloc(s, sizeof(char) * CHUNKY * contor))==NULL)
			{
				perror(NULL);
				exit(-1);
				free(s);
			}
		}
		contor++;
	}
	
	if(s[strlen(s)-1] == '\n')
		s[strlen(s)-1] = '\0';
	fclose(f);
	return s;
}



int main()
{
	FILE *src = NULL;
	char stream[]="test.txt", *s=NULL;
	
	s = read(src, stream);
	printf("%s\n", s);
	free(s);
}
*/
#define CHUNK 10

char *citire_eficienta(FILE *f, char *stream)
{
	char *s=NULL, aux[CHUNK]="";
	
	if((f = fopen(stream , "r"))==NULL)
	{
		perror("Eror desc fisi");
		exit(-1);
	}
	
	if((s = malloc(sizeof(char) * CHUNK))==NULL)
	{
		perror("Eroare");
		exit(-1);
	}
	s[0]=0; //e sirul vid acum
	int contor = 2;
	
	while(fgets(aux, CHUNK, f)!=NULL)
	{
		strcat(s, aux);
		
		if(strlen(aux) == CHUNK-1)
		{
			if((s = realloc(s, sizeof(char) * CHUNK * contor))==NULL)
			{
				perror("Eroare");
				exit(-1);
			}
		}
		contor++;
	}
	s[strlen(s)-1]='\0';
	
	fclose(f);
	
	return s;
}


char* transf_octal(char *s)
{
	int len = strlen(s);
	char aux[4]="";
	
	char *new_s = NULL;
	
	if((new_s = malloc(sizeof(char) * len * 3)) == NULL)
	{
		perror("Failed to allocate");
		exit(-1);
	}
	new_s[0]='\0';
	
	for(int i=0; i<len; i++)
	{
		sprintf(aux, "%o", s[i]);
		strcat(new_s, aux);
	}
		
	return new_s;
}


int main(void)
{
	char *s=NULL, *rez=NULL, stream[]="test.txt";
	FILE *src=NULL;
	
	s = citire_eficienta(src, stream);
	printf("%s", s);
	
	//rez = transf_octal(s);
	//printf("%s\n", rez);
	free(s);
	//free(rez);
}


















































