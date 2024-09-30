/*6. Se citesc doua nr intregi. Se se afiseze daca nr daca au acelasi semn sau nu

#include<stdio.h>
int main(void)
{
  signed int n, m; // signed inseamna ca poti baga si numere negative 
  scanf("%d",&n); //nu uita de & ampersant 
  scanf("%d", &m);
  printf("Cele doua numere sunt %d si %d\n", n, m); 
  if (n*m>=0) //e mai simplu decat sa pui mai multe conditii 
  	{
  		printf("Numerele au acelasi semn\n");
  	}
  else 
  	{
  		printf("Numerele nu au acelasi semn\n");
  	}
}

7. Se citeste un nr natural n. Sa se det cele mai mari doua nr impare, mai mici decat n

#include<stdio.h>
int main(void)
{
  unsigned int n;
  int a, b;
  printf("Introdu numarul ");
  scanf("%d", &n);
  
  if(n%2==0)
  {
  	a = n-1;
  	b = a-2;
  	printf("Numerele cautate sunt %d si %d\n", a, b);
  }
  else
  {
  	a = n-2;
  	b = a-2;
  	printf("Numerele cautate sunt %d si %d\n", a, b);
  }
  
 }
 9. De la un magazin se cumpara x kg de mere si y kg de pere, cu x si y valori REALE introduse de la tastatura. Stiind ca 1kg de mere costa 5 lei si 1kg de pere costa 7 lei, sa se verifice daca suma de 20 de lei ajunge pt cumpararea fructelor. 
 
 #include<stdio.h>
  
  int main(void)
  {
   float m, p, s;
   scanf("%f%f", &m, &p); // cu "%f" citim variabilele de tip float 
   s = m*5 + p*7;
   printf("Costul total este de %0.2f lei\n", s);  // "%0.2f" ne arata exact 2 zecimale
   if(s>20)
    	printf("NU ne ajung 20 de lei\n");
   else
   	printf("Ne ajung 20 de lei\n");
  }


  10. Se citesc 3 nr intregi de la tastatura (x,y,z). Sa se verifice daca z e in interiorul intervalului [x,y]
  
  #include<stdio.h>
  
  int main(void)
  {
   int x, y, z;
   scanf("%d%d%d", &x, &y, &z);
   printf("Numerele citite sunt %d, %d si %d\n", x, y, z);
   if(z>=x && z<=y)
   	printf("%d este in intervalul [%d, %d]\n", z, x, y);
   else
   	printf("NU");cle
  }
*/

  

