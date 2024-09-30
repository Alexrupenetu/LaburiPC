#include<stdio.h>
#include<stdlib.h>

struct Punct
	{
	int x,y;
	};
		
/* 1. Se citesc de la tastatura nr nat pana la EOF
-> Sa se stocheze nr cat mai eficient 
-> Sa se afiseze nr pare */

void citire(int *v)
{
	//primul element
	int value, len=1; int *t = NULL;
	
	scanf("%d", &value);
	v = realloc(t, len*sizeof(int));
	*v=value;
	
	while(scanf("%d", &value)!=EOF)
	{
		len++;
		t=v;
		if((v = (int*)realloc(t, len*sizeof(int)))==NULL)
		{
		printf("memorie insuficienta");
		free(t);
		exit(EXIT_FAILURE);
		}
		*(v+len-1)=value;	
	}
	
	printf("\n");
	for(int i=0; i<len; i++)
		if(*(v+i)%2==0)
			printf("%d ", *(v+i));
	printf("\n");
	
	free(v);
}

int main(void)
{
int *v;
citire(v);
}

