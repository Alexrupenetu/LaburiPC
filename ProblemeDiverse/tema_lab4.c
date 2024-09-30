/*
TEME SI APLICATII

1. Se cere un număr impar n>4. Să se deseneze cifra „8”, scris ca un pătrat cu o linie orizontală în mijloc, în așa fel încât pe verticală și pe orizontală să fie câte n steluțe. În program nu vor fi admise duplicări de cod.

2. Să se scrie o funcție care returnează maximul dintre 3 valori de tip întreg, primite ca parametri. Funcția nu va folosi nici o variabilă, cu excepția parametrilor săi. Se va testa funcția cu valori introduse de la tastatură. Citirea de la tastatura se va face în funcția main.
SOLUTIE
int maxim(int a, int b, int c)
{
	int max = a;
	if(b>max)
	{
		max = b;
	}
	if(c>max)
	{
		max = c;
	}
	
	return max;
}

#include<stdio.h>
int main(void)
{
	int a , b, c, maximul;
	printf("Introduceti trei numere\n");
	scanf("%d%d%d", &a, &b, &c);
	maximul = maxim(a,b,c);
	printf("Maximul dintre ele este %d\n", maximul);
}


3. Să se scrie o funcție care primește ca parametru o cifră și afișează cifra astfel: dacă este în intervalul [0,9] o afișează direct, altfel afișează A pentru 10, B pentru 11, ... până la 15 inclusiv.
SOLUTIE
#include<stdio.h>
int main(void)
{
	int x;
	printf("Introduceti un numar\n");
	scanf("%d", &x);
	
	switch(x)
	{
	 case 0:	
	 case 1:
	 case 2:	
	 case 3:
	 case 4:	
	 case 5:
	 case 6:	
	 case 7:
	 case 8:	
	 case 9:
	 	printf("%d\n", x);
	 	break;	
	 case 10:
	        printf("A\n");
	        break;
	 case 11:
	        printf("B\n");
	        break;
	 case 12:
	        printf("C\n");
	        break;
	 case 13:
	        printf("D\n");
	        break;
	 case 14:
	        printf("E\n");
	        break;
	 case 15:
	        printf("F\n");
	        break;
	 default:
	        printf("Introduceti un nr mai mic\n");
		
	}
	return 0;
}


4. Să se scrie o funcție care pentru un număr n afișează pe ecran: x^n+x^n-1+...+x+1.
De exemplu pentru n=3:   x^3+x^2+x+1.
SOLUTIE
void sumaputeri(int n)
{
   if(n==0)
      printf("1\n");
   if(n==1)
      printf("x + 1\n");
   if(n>=2)
   {
   for(int i=n; i>=2; i--)
      printf("x^%d + ", i);
      
   printf("x + 1\n");
   }
}


5. Scrieți o funcție care primește 3 parametri de tip float și îi afișează în ordine descrescătoare.
SOLUTIE 
void desc(float a, float b, float c)
{
  float minim = a;
  
  if(b<minim)
     minim=b;
  if(c<minim)
     minim=c;
  
  float maxim = a;
  
  if(c>maxim)
     maxim=c;
  if(b>maxim)
     maxim=b;
  
    
  float mijloc = a + b + c - minim - maxim;
     
  printf("Ordinea desc este %0.1f %0.1f si %0.1f\n", maxim, mijloc, minim); 

}

6. Scrieți o funcție care primește ca parametri trei numere n, b și c, cu c în intervalul [0,b) și returnează de câte ori apare cifra c în numărul n, dacă acesta s-ar afișa în baza b. 


7. Dacă numărul p este prim și numărul a nu este divizibil cu p, secvența a, a^2, a^3, .. , a^n devine 1 când este calculată modulo p. Scrieți o funcție care primește p și a, (numerele respectă condiția, nu este nevoie de verificare) și returnează cel mai mic n pentru care șirul devine 1.
De exemplu pentru p = 7, a = 4 => n = 3    
sau pentru p = 11, a = 25 => n = 5
SOLUTIE

#include<stdio.h>

int sumaputeri(int a, int n)
{
  int an=1, suma;
  
  for(int i=1; i<=n; i++)
      an=an*a;
    
  suma = a*(an-1)/(a-1);
  return suma;  
}
int main(void)
{
	int a, p, n=1;
	printf("Introduceti p si a ");
	scanf("%d%d", &p, &a);
	printf("p=%d si a=%d\n", p, a);
	
	while(sumaputeri(a,n)%p!=0)
	      n++;
	     
        printf("n=%d\n",n);
}


Probleme cu funcții recursive (extracurricular)

    1. Scrieți o funcție recursivă care implementează șirul lui Fibonacci, apoi printați numărul de apeluri recursive pentru fiecare număr folosind un parametru dat prin adresă din main.
    SOLUTIE
    #include<stdio.h>

int fibo(int n)
{
	static int count=0;
	count++;
	
	printf("fibo a fost apelata de %d ori\n", count);

	if(n<=1)
	   return n;
	else  
	{   
	   return fibo(n-1) + fibo(n-2);
	}
}

int main(void)
{
	fibo(8);
}

    2. Scrieți o funcție recursivă care returnează cea mai semnificativă cifră a unui număr natural scris în baza 10. (asta cred ca inseamna prima cifra?)
       SOLUTIE
       int cifra(int n)
{
	if(n<10)
	 {
	 	return n;
	 }
	else
	 {
	 	return cifra(n/10);
	 }
}

    3. Scrieți o funcție recursivă care primește ca paramteru un număr natural n și returnează numărul format selectând doar cifrele pare ale acelui număr.
    SOLUTIE
    int npar(int n)
{
	if(n<10)
	{
		if(n%2==0)
		{
			return n;
		}
		else 
		{
			return 0;
		}
	}
	else
	{
	  if(n%2==0)
	  {
	  	return n%10 + 10*npar(n/10);
	  }
	  else
	  {
	  	return npar(n/10);
	  }
	}
}

    4. Scrieți o funcție recursivă care returnează numărul primit ca și parametru, interpretat în baza 16 rezultat din cifrele numărului respectiv.
    De exemplu f(312) = 3*256+1*16+2*1=786 
    SOLUTIE
    
    #include<stdio.h>
#include<math.h>

int baza(int n)
{
	static int p=0;
	if(n<10)
	  {
	  	return n;
	  }
	else
	  {
	  	return n%10 * (int)pow(16,p) + baza(n/10);
	  	printf("%d\n", (int)pow(16,p));
	  	p++;
	  }
}

int main(void)
{
	//printf("%d\n", baza(312));
	baza(312);
}
 
*/

#include<stdio.h>

void acoperis(int n, int m)
{
	for(int i=0; i<n; i++)
	   {
	    for(int j=0; j<m; j++)
	    	{
	    		if(i+j==n-1 || j-i==n-1)
	    		   printf("%c",'*');
	    		   
	    		else
	    		   printf("%c",' ');
	    	}
	    printf("\n");
	   }
}

int main(void)
{
	acoperis(5, 9);
}

















