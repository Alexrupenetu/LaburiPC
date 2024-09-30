#include<stdio.h>
#include<stdint.h>

void read_array(int *v, int *size)
{
	for(int i=0; i<*size; i++)
		scanf("%d", (v+i));
}

void print_array(int *v, int *size)
{
	for(int i=0; i<*size; i++)
		printf("%d ", *(v+i));
}


int count(uint8_t n) //numara bitii de 1 dintr un numar 
{
	uint8_t mask=1;
	int count=0;
	for(int i=7; i>=0; i--)
		if(n&(mask<<i))
			count++;
		
	return count;
}

void new_vector(int *t, int *v, int *size)
{
	for(int i=0; i<*size; i++)
		*(t+i) = count(*(v+i));	
}

//8. Se cere sa se stearga dintr un vector toate acele elemente care sunt urmate de un nr strict mai mare ca ele, pastrandu-se ordinea 

void ex8(int *v, int *size)
{
	
   for(int i=0; i<*size; i++)
   	if(*(v+i)<*(v+i+1))
   		{
   		for(int j=i; j<*size-1; j++)
   		    {
   		    	*(v+j) = *(v+j+1);
   		    }
   		    
   		 i--;
   		 *size= *size-1;
   		 }
   		
   print_array(v,size);

}

//9. Sa se insereze inainte de fiecare valoarea impara din vectorul original valoarea 0

void ex9(int *v, int *size)
{
	for(int i=0; i<*size; i++)
	{
		if(*(v+i)%2!=0)
			{
				for(int j=*size; j>i; j--) //o luam de la coada si lasam un spatiul "gol"
					*(v+j)=*(v+j-1);
					
				*(v+i)=0; //pe care il "umplem" aici
				i++;
				*size = *size +1;
			}
	}
	
	 print_array(v,size);
}

//DUPA fiecare valoare impara 

void ex9v2(int *v, int *size)
{

	for(int i=0; i<*size; i++)
	{
		if(*(v+i)%2!=0)
		{
			for(int j=*size; j>i+1; j--)
				*(v+j)=*(v+j-1);
			*(v+i+1)=0;
			i=i+1;
			*size = *size + 1;
		}
	}
	 print_array(v,size);
}

//Sa se sorteze vectorul ai nr poz sa fie inaintea celor negative
void sortare_poz_neg(int *v, int *size)
{
	for(int i=0; i<*size; i++)
		for(int j=i+1; j<*size; j++)
			if((*(v+i)<0) && (*(v+j)>0))
			{
			int aux = *(v+i);
			*(v+i) = *(v+j);
			*(v+j) = aux;
			}
	print_array(v,size);
			
}

//11.Sa se stearga toate duplicatele din vector, pastrandu se ordinea elementelor

void stergere_duplicate(int *v, int *size)
{
	for(int i=0; i<*size-1; i++)
		for(int j=i+1; j<*size; j++)
			if(*(v+i)==*(v+j))
			{
				for(int k=j; k<*size-1; k++)
					*(v+k)=*(v+k+1);
				*size = *size-1;
				j--;
			}
			
	print_array(v,size);	
		 	
}

//12. Sa se insereze dupa fiecare element din vectorul original patratul lui

void inserare_patrat(int *v, int *size)
{
	for(int i=0; i<*size; i++)
	{
		for(int j=*size; j>i+1; j--)
		  *(v+j)=*(v+j-1);
		  
		*(v+i+1)=*(v+i) * *(v+i);
		i++;
		*size = *size + 1;
	}
	
	print_array(v,size);
}

// 13.Sa se insereze dupa fiecare pereche din vectorul original suma si produsul numerelor din pereche 

void suma_produs(int *v, int *size)
{
	
		
}

/*1. Se citeste un numar n <= 100 si n numere intregi pozitive.
   Se cere sa se sorteze aceste numere astfel incat numerele cu numar par de biti 
   de 1 sa se afle dupa cele cu numar impar de biti de 1.*/
   
void sortare_nrbiti(int *v, int *size)
{
	for(int i=0; i<*size-1; i++)
	   for(int j=i+1; j<*size; j++)
	   	if((count(*(v+i))%2==0) && (count(*(v+j))%2==1))
	   	{
	   	int aux = *(v+i);
	   	*(v+i) = *(v+j);
	   	*(v+j) = aux;
	   	}
	print_array(v,size);
}

/*2. Se citeste un numar n<=100, un numar k<=64 si n numere intregi pe 64 de biti.
   Se cere sa se elimine din vector numerele care au k biti de 1.*/
   
void eliminare_biti(int *v, int *size, int k)
{
	for(int i=0; i<*size; i++)
		if(count(*(v+i))==k)
		{
			for(int j=i; j<*size-1; j++)
				*(v+j)=*(v+j+1);
			i--;
			*size = *size-1;
		}
	print_array(v,size);
}

/*Se citeste un numar n<=100 si n numere pe 8 biti. Se cere sa se numere cate numere isi gasesc oglinditul in scrierea binara in sir si sa se afiseze aceste perechi. (ex nr oglindite: 00011010 si 01011000)*/
   
void show_8bits(uint8_t n)
{
	uint8_t mask=1;
	
	for(int i=7; i>=0; i--)
		{
		printf("%d", (n&(mask<<i))>>i);
		
		if(i%4==0)
			printf(" ");
		}
	printf("\n");
		
}
  
void oglindit(uint8_t n)
{
	uint8_t mask=1, ogl=0;
	
	/*for(int i=0; i<8; i++)
		{
		ogl = (ogl<<1) | (n&1);
		n=n>>1;
		show_8bits(ogl);
		}*/
	int k=6;
	for(int i=0; i<8; i++)
	{
	ogl = (ogl<<1) | (n&(mask<<i));
	show_8bits(ogl);
	}
}



int main(void)
{
	int v[100]={5,2,3,9,8}, size=5;
	//read_array(v, &size);
	//new_vector(t, v, &size);
	//print_array(t,&size);	
	//printf("%d", count(2));
	//ex9v2(v,&size);
	//sortare_poz_neg(v, &size);
	//stergere_duplicate(v,&size);
	//inserare_patrat(v, &size);
	//sortare_nrbiti(v,&size);
	//eliminare_biti(v,&size,2);
	show_8bits(111);
	oglindit(111);
}




