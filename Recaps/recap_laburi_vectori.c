#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void print_vector(int *array, int *size)
{
	for(int i=0; i<*size; i++)
		printf("%d ", *(array + i));
	printf("\n");
}

//LABORATOR 6 + 7 CV: VECTORI + POINTERI (O sa rezolv tot cu pointeri)


//Se cere să se șteargă din vector toate acele elemente care sunt urmate de un număr strict mai mare decât ele, păstrându-se ordinea elementelor

void stergere_el_mai_mari(int *array, int size)
{
	for(int i=0; i<size; i++)
		if(*(array + i) < *(array + i +1))
			{
				for(int j = i ; j<size; j++)
					*(array + j) = *(array + j + 1);
				i--;
				size--;
			}
}

//Se citește un număr n<=10 și apoi n numere pozitive. Se cere să se insereze înainte de fiecare valoare impară din vectorul original valoarea 0.


void inserare_valori(int *array, int *size)
{
	for(int i=0; i<*size; i++)
		if(*(array+i)%2==1)
			{
				for(int j = *size; j>i; j--)
					*(array+j) = *(array + j -1);
				*(array + i) = 0;
				*size = *size + 1;
				i++;
			}
	print_vector(array, size);
}

//Se citește un număr n<=10 și apoi n numere întregi. Se cere să se insereze după fiecare valoare din vectorul original pătratul ei.

void inserare_patrat(int *array, int *size)
{
	for(int i=0; i<*size; i++)
		{
		for(int j=*size; j>i+1; j--)
			*(array + j) = *(array + j -1);
			
		*(array + i + 1) = *(array + i) * *(array + i);
		*size = *size + 1;
		i++;
		}
	print_vector(array, size);	
}

//Se citește un număr n<=10 și apoi n numere întregi. Se cere să se șteargă toate duplicatele (ori de câte ori apar acestea) din vector, păstrându-se ordinea elementelor.

void sterge_duplicate(int *array, int *size)
{
	for(int i=0; i<*size; i++)
		for(int j=i+1; j<*size; j++)
			if(*(array + i) == *(array + j))
			{
				for(int k=j ; k<*size; k++)
					*(array + k) = *(array + k + 1);
				*size = *size - 1;
				i--;
			}
	print_vector(array, size);
}

//Se citesc n<=10 valori întregi. Folosind doar pointeri, fără niciun fel de indexare, să se afișeze toate valorile care au cel puțin un duplicat. (Inclusiv citirea se va face cu pointeri.)

int are_duplicat(int *array, int *size, int value)
{
	int contor = 0;
	for(int i=0; i<*size; i++)
		if(*(array + i) == value)
			contor++;
	if(contor>1)
		return 1;
	else
		return 0;
			
}

void afisare_duplicat(int *array, int *size)
{

	int contor[1000]={0};
	for(int i=0; i<*size; i++)
		if(are_duplicat(array, size, *(array+i))!=0)
			{
				if(contor[*(array+i)] == 0)
					{
					printf("%d ", *(array+i));
					contor[*(array+i)]++;
					}
			}
}

//Să se implementeze, fără a se folosi indecși, următorul program: se citește pe rând câte o valoare întreagă și se inserează într-un vector, astfel încât vectorul să fie mereu sortat crescător. După fiecare inserare se va afișa noul vector. Programul se termină la citirea valorii 0. Presupunem că vectorul va avea maxim 100 de elemente.

void sortare()
{
	int v[100], index=0;
	int value, aux;
	while(1)
	{
		scanf("%d", &value);
		if(value!=0)
		{
			*(v + index) = value;
			index++;
			for(int i=0; i<index; i++)
				for(int j=i+1; j<index; j++)
					if(*(v+i) > *(v+j))
					{
						aux = *(v+i);
						*(v+i) = *(v+j);
						*(v+j) = aux;
					}
			print_vector(v, &index);
		}
		else
		{
		break;
		}
	}
}

int main(void)
{
	//int array[50] = {1, 2, 2, 2, 1, 4, 3, 5, 4, 6};
	//int size = 10;
	//print_vector(array, &size);
	//afisare_duplicat(array, &size);
	sortare();
	
}
































