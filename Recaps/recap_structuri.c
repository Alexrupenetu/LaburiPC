#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdint.h>
#include<math.h>

/* PROBLEMA2 
typedef struct
{
int ora;
int minut;
int sec;
}data_ora;

typedef struct
{
data_ora ceas;
float temp;
}caca;

caca v[11];
data_ora ceas1, ceas2;

int interval(data_ora ceas1, data_ora ceas2, data_ora ceva)
{
	if(ceas1.ora < ceva.ora && ceva.ora < ceas2.ora)
		return 1;
	else if(ceas1.ora == ceva.ora)
		{
			if(ceva.minut>ceas1.minut)
				return 1;
			else if(ceva.minut == ceas1.minut)
				{
					if(ceva.sec >= ceas1.sec)
						return 1;
					else
						return 0;
				}
			else if(ceva.minut < ceas1.minut)
				return 0;
		}
	else if(ceas2.ora == ceva.ora)
		{
			if(ceva.minut<ceas2.minut)
				return 1;
			else if(ceva.minut == ceas2.minut)
				{
					if(ceva.sec <= ceas2.sec)
						return 1;
					else
						return 0;
				}
			else if(ceva.minut>ceas2.minut)
				return 0;
		}
	else if(ceva.ora<ceas1.ora || ceva.ora > ceas2.ora)
		return 0; 
		
}

int main(void)
{
	int n;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
		scanf("%d:%d:%d - %g ", &v[i].ceas.ora, &v[i].ceas.minut, &v[i].ceas.sec, &v[i].temp);
		
	scanf("%d:%d:%d - %d:%d:%d", &ceas1.ora, &ceas1.minut, &ceas1.sec, &ceas2.ora, &ceas2.minut, &ceas2.sec);
	
	for(int i=0; i<n; i++)
		printf("%d:%d:%d - %g\n", v[i].ceas.ora, v[i].ceas.minut, v[i].ceas.sec, v[i].temp);
		
		
	for(int i=0; i<n; i++)
		if(interval(ceas1, ceas2, v[i].ceas)!=0)
			printf("%g ", v[i].temp);
			
}


typedef struct
{
char nume[50];
int varsta;
}Persoana;

Persoana p;

char *nume_pers(char *string)
{
	int len; char ch;
	len = strlen(string);
	
	ch = toupper(string[0]);
	string[0]=ch;
	
	for(int i=1; i<len; i++)
		if(string[i-1]==' ')
			string[i] = toupper(string[i]);
		else
			string[i] = tolower(string[i]);
		
	return string;
}

int main()
{
	fgets(p.nume, 50, stdin);
	getchar();
	scanf("%d", &p.varsta);
	strcpy(p.nume, nume_pers(p.nume));
	p.nume[strlen(p.nume)-1]=0;
	printf("%s - %d\n", p.nume, p.varsta);
}


typedef struct
{
float x, y;
}data;

void acelasi_y(data punct[], int n)
{
	float v[100]; int len=0;
	
	for(int i=0; i<n; i++)
		{
		v[len] = punct[i].y;
		len++;
		}
	//stergem duplicatele din v		
	for(int i=0; i<len; i++)
		for(int j=i+1; j<len; j++)
			if(v[i] == v[j])
				{
					for(int k=i; k<len; k++)
						v[k] = v[k+1];
					len--;
					i--;
				}
	for(int i=0; i<len; i++)
		for(int j=0; j<n; j++)
			if(v[i] == punct[j].y)
					printf("(%g, %g)\n", punct[j].x, v[i]);
	
		
}

int main()
{
	int n;
	data punct[100];
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	 	scanf(" %g %g ", &punct[i].x, &punct[i].y);
	 	
	 acelasi_y(punct, n);	
	 
}


//PROBLEMA 5 :,)
#define SIZE 10
//Enum pt tipul de dieta + Enum pt tipul de animal
//Cate un union pt fiecare caracteristica
//Un union mare pt toate caracteristicile 
//UN struct care sa le cuprinda pe toate

typedef enum
{
ierbivor, 
omnivor, 
carnivor,
}tip_dieta;

typedef enum
{
insecta,
pasare, 
mamifer, 
peste, 
}tip_animal;

typedef union
{
uint8_t picioare;
uint8_t durata_viata;
}Caract_Insecta;

typedef union
{
uint8_t vit_zbor;
uint8_t aripi;
}Caract_Pasare;

typedef union
{
uint8_t greutate;
uint8_t inaltime;
tip_dieta dieta;
}Caract_Mamifer;

typedef union
{
uint8_t greutate;
uint8_t adancime;
float salinitate;
}Caract_Peste;

typedef union
{
	Caract_Insecta caract_insecta;
	Caract_Pasare caract_pasare;
	Caract_Mamifer caract_mamifer;
	Caract_Peste caract_peste;
}Caract_Animal;

typedef struct
{
	tip_animal type;
	Caract_Animal caract;
}data;

//arhitectura pe 64 de biti - deloc eficient 

void print_animal(const data *d)
{
	printf("Tip animal ");
	
	switch(d->type)
	{
	case insecta:
		printf("Insecta\n");
		printf("Picioare %hd\n", d->traits.nr_picioare);
		printf("Durata viata %hd\n", d->traits.durata_viata);
		break;
	case pasare:
		printf(" Pasare\n");
		printf("Viteza zbor %hd\n", d->traits.vit_zbor);
		printf("Anv aripi %hd\n", d->traits.aripi);
		break;
	
	case mamifer:
		printf("Mamifer\n");
		printf("Greutate %hd\n", d->traits.greutate);
		printf("Inaltime %hd\n", d->traits.inaltime);
		switch(d->traits.tip_dieta)
		{
			case carnivor:
			{
				printf("Carnivor\n");
				break;
			}
			case ierbivor:
			{
				printf("Ierbivor\n");
				break;
			}
			case omnivor:
			{
				printf("Omnivor\n");
				break;
			}
				
		}
		break;
	case peste:
		printf("Peste\n");
		printf("Greutate %hhu\n", d->traits.weight);
		printf("Adancime %hhu\n", d->traits.depth);
		printf("Salinitate %f\n", d->traits.salinitate);
		break;
	}
	printf("\n");
}

void print_animals(data *animal, int size)
{	

	for(int i=0; i<size; i++)
		print_animal(&animal[i]);

}

int main(void)
{ 
	int i=0;
	data ANIMAL[10];
	
	data animal1;
	animal1.type = insecta;
	animal1.traits.durata_viata = 5;
	animal1.traits.nr_picioare = 4;
	ANIMAL[i++] = animal1; 
	
	data animal2;
	animal2.type = pasare;
	animal2.traits.vit_zbor = 100;
	animal2.traits.aripi = 10;
	ANIMAL[i++] = animal2; 
	
	data animal3;
	animal3.type = mamifer;
	animal3.traits.tip_dieta = carnivor;
	animal3.traits.greutate = 200;
	animal3.traits.inaltime = 150;
	ANIMAL[i++] = animal3; 
	
	data animal4;
	animal4.type = peste;
	animal4.traits.weight = 15;
	animal4.traits.depth = 30;
	animal4.traits.salinitate = 3.5;
	ANIMAL[i++] = animal4;
	
	
	print_animals(ANIMAL, i);
	
} 
*/

#define CHUNK 5

typedef struct
{
	int x;
	int y;
}data;

data* read(data *array, int *len)
{
	*len =  CHUNK; 
	int curr_len = 0, X, Y;
	
	if((array = (data*)malloc(sizeof(data)* (*len)))==NULL)
	{
		perror("Memorie insuficienta!");
		exit(-1);
	}
	
	while(scanf("%d.%d", &X, &Y) != EOF)
	{
		array[curr_len].x = X;
		array[curr_len].y = Y;
		curr_len++;
		
		if(curr_len == *len)
		{
			*len += CHUNK;
			if((array = (data*)realloc(array, sizeof(data) * (*len)))==NULL)
				{
					perror("Memorie insuficienta!");
					exit(-1);
				}
		}
	}
	
	if((array = (data*)realloc(array, sizeof(data) * curr_len))==NULL)
				{
					perror("Memorie insuficienta!");
					exit(-1);
				}
	*len = curr_len;
	return array;
	
}

float dist_origine(int x, int y)
{
	float dist;
	dist  = sqrt(x*x + y*y);
	return dist;
}

void dist_max(data *array, int len)
{
	float min = 100000, dist;
	data pereche;
	for(int i=0; i<len; i++)
		{
			dist = dist_origine(array[i].x, array[i].y);
			if(dist<min)
			{
				min = dist;
				pereche.x = array[i].x;
				pereche.y = array[i].y;
			}  
		}
	printf("Perechea este (%d, %d)\n", pereche.x, pereche.y);
}

int main()
{
	data *v = NULL;
	int len = 0;
	v = read(v, &len);
	dist_max(v, len);
	free(v);
}

























