#include<stdio.h>
/* 
1. Se citeste un nr intreg n>10. Sa se afiseze toata seria de nr incepand cu n, urmatorul 
nr fiind obtinut prin scaderea din cel anterior a n/10, atat timp cat n>10.
2. Se citeste un nr intreg n>1. Sa se afiseze seria "1+2+...+n = s", unde s e suma.
SOLUTIE:

unsigned int n, s=0;
  printf("Introdu numarul");
  scanf("%d", &n);
  
  printf("1 + ");
  s=1; 
  for(int i=2; i<n; i++)
  {
  	s = s + i;
  	printf("%d + ", i);
  }
  s = s + n;
  printf("%d = %d\n", n, s);
  
3. Se citeste un nr n>1. Sa se afiseze folosind stelute un patrat gol, avand latura de n stelute.
SOLLUTIE:

  unsigned int n;
  printf("Introdu numarul ");
  
  scanf("%d", &n);
  
  for(int i=0; i<n; i++)
     {
     	for(int j=0; j<n; j++)
     	  {
     	   if(i==0 || i==n-1 || j==0 || j==n-1)
     	    	{
     	    		printf("*");
     	    	}
     	   else 
     	    	{	
     	    		printf(" ");
     	    	}
     	    
     	   printf(" "); 
     	  }
     	   printf("\n");
     }
      

4. Se citeste un nr intreg n>2. Sa se afiseze folosind stelute litera N, formata cu laturile 
si diagonala unui patrat de latura n.  
SOLUTIE:

unsigned int n;
  printf("Introdu numarul ");
  scanf("%d", &n);
  
  for(int i=0; i<n; i++)
  {
  	for(int j=0; j<n; j++)
  		{
  			if(i==j || j==0 || j==n-1)
  				{
  					printf("*");
  				}
  			else   
  				{
  					printf(" ");
  				}
  		}
  	printf("\n");	
  		
  }
  
 5. 
*/

int main(void)
{
  
  
  
}





















