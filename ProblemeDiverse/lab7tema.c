#include<stdio.h>
#include<stdint.h>


/*Se citesc două variabile, a și b, de tip întreg. Să se stocheze într-un pointer adresa variabilei care conține valoarea maximă și apoi să se afișeze valoarea pointată*/

void ex1(int a, int b)
{
 int *p;
 if(a>b)
 p = &a;
 else
 p = &b;
 
 printf("%d", *p);
}

/*Să se scrie un program care citește un număr n<10 iar apoi citește 2 vectori v1 și v2 de câte n elemente de tip int. Pentru citirea elementelor unui vector se folosește o funcție citire(v,n). Se va implementa o funcție egal(v1,v2,n), care testează dacă toate elementele din v1 sunt egale cu cele din v2 la poziții corespondente.*/

void citire(int *v, int n)
{
	int value, i;
	printf("Introduceti valorile vectorului ");
	for(i=0; i<n; i++)
	{
		scanf("%d", &value);
		*(v+i) = value;
	}
	printf("\n");
}

void egal(int *v1, int *v2, int n)
{
	int ok=1;
	for(int i=0; i<n; i++)
		if(*(v1+i) != *(v2+i))
			ok=0;
			
	if(ok!=0)
		printf("DA");
	else
		printf("NU");	
	
}

void ex2(int n, int *v1, int *v2)
{
	citire(v1,n);
	citire(v2,n);
	egal(v1,v2,n);
	
}

/*Să se citească de la tastatură două variabile de tip double (se citește cu %lf, nu cu %g!!!) și să se afișeze numele variabilei care se află la adresa cea mai mică de memorie utilizând pointeri.*/
 void ex3(double a, double b)
 {
 	double *p_a, *p_b;
 	p_a = &a;
 	p_b = &b;
 	
 	if(p_a < p_b)
 		printf("Adresa lui p_b este %p", p_b);
 	else 
 		printf("Adresa lui p_a este %p", p_a);
 }
 
 
 /*Scrieți un program care interschimbă valorile a două variabile de tip întreg utilizând pointeri*/
 
 void swap_p(int a, int b)
 {
 	int *x;
 	int *y;
 	int aux;
 	
 	x = &a;
 	y = &b;
 	
 	aux = *x;
 	*x = *y;
 	*y = aux;
 	
 	a = *x;
 	b = *y;
 	
 	printf("a=%d si b=%d\n", a, b);
 }
 
 
 /*Să se afișeze câte elemente negative sunt în vectorul {7, -5, 4, 3, -9, 2, -8} utilizând pointeri, fără indecși. (Fără indecși înseamnă că în cod nu va exista niciun v[i])*/
 
 void el_negative(int *v, int n)
 {
 	citire(v,n);
 	int contor = 0;
 	for(int i=0; i<n; i++)
 	{
 		if(*(v+i)<0)
 			contor++;
 	}
 	printf("contor=%d\n", contor);
 }
 
 /*Să se afișeze minimul elementelor din vectorul {7, -5, 4, 3, -9, 2, -8} utilizând pointeri, fără indecși.*/
 void minim(int *v, int n)
 {
 	citire(v,n);
 	int minim = 100;
 	
 	for(int i=0; i<n; i++)
 		if(*(v+i)<minim)
 			minim = *(v+i);
 			
 	printf("Minimul este %d", minim);
 
 }
 
 /*Se citește un număr n (n<=10) și apoi n numere întregi. Se cere să se sorteze aceste numere în ordine descrescătoare utilizând pointeri, fără indecși. (Inclusiv citirea se va face cu pointeri.)*/
 
 void ordine_desc(int *v, int n)
 {
 	int value, i;
	printf("Introduceti valorile vectorului ");
	for(i=0; i<n; i++)
	{
		scanf("%d", &value);
		*(v+i) = value;
	}
	printf("\n");
 	
 	int aux;
 	
 	for(int i=0; i<n-1; i++)
 		for(int j=i+1; j<n; j++)
 			if(*(v+i)<*(v+j))
 				{
 				aux = *(v+i);
 				*(v+i) = *(v+j);
 				*(v+j) = aux;
 				}
 				
 	for(int i=0; i<n; i++)
 		printf("%d ",*(v+i));
 				
 }
 
 /*Să se șteargă din vectorul {5, 8, 1, 4, 2, 6, 9} toate elementele pare, păstrând neschimbată ordinea elementelor, după care să se afișeze noul vector. Utilizați pointeri, fără indecși.*/
 
 void sterge_el_pare(int *v, int n)
 {
 	citire(v,n);
 	for(int i=0; i<n; i++)
 		if(*(v+i)%2==0)
 		 	{
 		 	for(int j=i+1; j<n; j++)
 		 		*(v+j-1)=*(v+j);
 		 	 n--;
 		 	 i--;
 		 	}
 	for(int i=0; i<n; i++)
 		printf("%d ",*(v+i));
 }
 
 /*Se dă vectorul {7, -5, 4, 3, -9, 2, -8}. Să se insereze înainte de fiecare valoare din vectorul original negativul ei. Utilizați pointeri, fără indecși.*/
 
 void inserare_negative(int *v, int n)
 {
 	for(int i=0; i<n; i++)
 	  {
 	   for(int j=n; j>i; j--)
 	   	*(v+j) = *(v+j-1); //basically dublam valorea v[i] 
 	   	
 	   *(v+i) = -*(v+i);
 	   n++;
 	   i++; //sarim peste pozitia asta 
 	  }
 	for(int i=0; i<n; i++)
 		printf("%d ",*(v+i));
 }
 
 /*Se citesc n<=10 valori întregi. Folosind doar pointeri, fără niciun fel de indexare, să se afișeze toate valorile care au cel puțin un duplicat. (Inclusiv citirea se va face cu pointeri.)*/
 
 void afisare_duplicate(int *v, int n)
 {
 	int aux;
 	citire(v,n);
 	//mai intai sortam vectorul ca sa ne asiguram ca duplicatele sunt unele langa altele
 	for(int i=0; i<n-1; i++)
 	   for(int j=i+1; j<n; j++)
 	   	if(*(v+i)>*(v+j))
 	   	{
 	   	aux = *(v+i);
 	   	*(v+i) = *(v+j);
 	   	*(v+j) =aux;
 	   	}
        int lastValue, currentValue, lastValueprinted;
        lastValue = *v;
        lastValueprinted = lastValue-1; //evident e fals dar avem nevoie sa fie diferite
        
        for(int i=1; i<n; i++)
         {
         currentValue = *(v+i);
         
         if(currentValue == lastValue)
         {
         	if(currentValue!=lastValueprinted)
         	{
         	printf("%d ",currentValue);
         	lastValueprinted = currentValue;
         	}
         }
         
         lastValue=currentValue;
         }
 }
 
int main(void)
{
	int v1[20]={7, -5, 4, 3, -9, 2, -8}, v2[10];
	//ex1(5,7); printf("\n");
	//ex2(5,v1,v2);
	//ex3(5.3, 67);
	//swap_p(7,10);
	//el_negative(v1,7);
	//minim(v1,7);
	//ordine_desc(v1,5);
	//sterge_el_pare(v1,7);
	//inserare_negative(v1,7);
	afisare_duplicate(v2,7);
	
}
