/*PROBLEMA 
Vehicul 
* nr roti 
* tip vehicul (trotineta, bicicleta, automobil, autobuz)
*caracteristica *tip trotineta(clasica, electrica) - tip vehicul trotineta 
		*nr viteze -> tip vehicul bicicleta 
		*an fabricatie -> tip vehicul automobil
		*nr locuri -> tip vehicul autobuz 
		
Definim tipurile de date "cat mai abstract posibil" cu type def ai sa putem defini
vehicul v[100]


#include<stdio.h>
#include<stdint.h>

typedef enum //en_tip_vehicul -> asta e numele enumului (nu l folosim la nimic aici)
{
	trotineta,
	bicicleta,
	automobil,
	autobuz	
}TIP_VEHICUL; //asta este numele tipului

typedef enum
{
	clasica,
	electrica
}TIP_TROTINETA;

typedef union
{
	TIP_TROTINETA tip_trotineta;
	uint8_t nr_viteze;
	uint16_t an_fabricatie;
	uint8_t nr_locuri;
}CARACTERISTICA;

typedef struct
{
	uint8_t nr_roti;
	TIP_VEHICUL tip_vehicul;
	CARACTERISTICA car;
}VEHICUL;


void printVehicul(const VEHICUL *v)
{
	printf("nr roti %d\n", v->nr_roti);
	printf("tip vehicul: ");
	switch(v->tip_vehicul)
	{
	case trotineta: 
		{
		printf("trotineta\n");
		switch(v->car.tip_trotineta)
		{
		case clasica:
		{
		printf("clasica\n");
		break;		
		}
		case electrica:
		{
		printf("electrica\n");
		break;
		}
		}
		break;
		}
	case bicicleta:
		{
		printf("bicicleta - nr viteze: %d\n", v->car.nr_viteze);
		break;
		}
	case automobil:
		{
		printf("automobil - an fabricatie: %d\n", v->car.an_fabricatie);
		break;
		}
	case autobuz:
		{
		printf("autobuz - nr locuri: %d\n", v->car.nr_locuri);
		break;
		}
	}
}

void print_vehicule(const VEHICUL *v)
{
printf("nr roti:%d\n")
}

int main(void)
{

/*TIP_VEHICUL tip_vehicul;
	tip_vehicul = autobuz;
TIP_TROTINETA tip_troti;
	tip_troti = electrica;
	
	VEHICUL v;
	
	//printf("%ld\n", sizeof(CARACTERISTICA)); -> afiseaza 4 

	VEHICUL array[10];
	
	array[0].nr_roti = 2;
	array[0].tip_vehicul = trotineta;
	array[0].car.tip_trotineta = clasica;
	
	
	array[1].nr_roti = 2;
	array[1].tip_vehicul = trotineta;
	array[1].car.tip_trotineta = electrica;
	
	array[2].nr_roti = 2;
	array[2].tip_vehicul = bicicleta;
	array[2].car.nr_viteze = 18;

	array[3].nr_roti = 4;
	array[3].tip_vehicul = automobil;
	array[3].car.an_fabricatie = 2023;
	
	array[0].nr_roti = ;
	array[0].tip_vehicul = trotineta;
	array[0].car.tip_trotineta = clasica;


}

Alta problema 

typedef struct
{
char judet[FIELD_LEN+1];
char categorie[FIELD_LEN+1]
char 
}
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

#define LINE_SIZE 2048
#define FIELD_LEN 256

typedef struct
{
	char judet[FIELD_LEN+1];
	char categorie[FIELD_LEN+1];
	char marca[FIELD_LEN+1];
	char descriere[FIELD_LEN+1];
	uint32_t total;
}AUTO;

int main(void)
{
	FILE *f=NULL;
	char line[LINE_SIZE];
	
	if((f = fopen(), "r")==NULL)
	{
	perror(NULL);
	exit(-1);
	}
	
	
}
































































