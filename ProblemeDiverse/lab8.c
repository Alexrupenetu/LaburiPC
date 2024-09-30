 /*Numar cuvinte dintr un fisier 
#include<stdio.h>

int main(void)
{
 int c=0, cuvant=0, contor=0;
 
 while((c=getchar())!=EOF)
 {
 	if(c>='a' && c<='z')
 	{
 		cuvant=1;
 	}
 	else
 	{
 	if(cuvant!=0)
 	{
 		contor++;
 		cuvant=0;
 	}
 	}
 }
 
 if(cuvant)
 {
 	contor++;
 }
 
 printf("In fisier sunt %d cuvinte\n", contor);
}



#include<stdio.h>

int main(void)
{
int c=0, inComentariu=0;

while((c=getchar())!=EOF)
{
 if(inComentariu==0)
 {
 	if(c=='/')
 	{
 	 	int urm_c = getchar();
 	 	if(urm_c=='/')
 	 	{
 	 		inComentariu=1;
 	 	}
 	 	else if (urm_c=='*')
 	 	{
 	 		inComentariu=2;
 	 	}
 	 	else
 	 	{
 	 	putchar(c);
 	 	putchar(urm_c);
 	 	}
 	}
 	else
 	{
 	putchar(c);
 	}
 }
 else if(inComentariu==1 && c=='\n')
         inComentariu=0;
 else if(inComentariu==2)
 {
 	if(c=='*' && getchar()=='/')
 	   inComentariu=0;
 }
}
return 0;
}

4. Scrieți un program, folosind getchar() si putchar() care, primind la stdin un fișier text va tipari la iesirea standard acelasi fisier text dar va schimba literele mari intalnite in fisier in litere mici iar cele mici in litere mari.


#include<stdio.h>
#include<ctype.h>

int main(void)
{
int c=0; 

while((c=getchar())!=EOF)
{
	if(islower(c))
	{
	putchar(toupper(c));
	}
	else if(isupper(c))
	{
	putchar(tolower(c));
	}
	else
	{
	putchar(c);
	}
}
}

7. Scrieti un program care tipareste la iesire textul citit de la intrarea standard, modificat astfel incat orice litera de la inceputul unui cuvant e transcrisa ca litera mare. La sfarsit, programul va tipari numarul total de cuvinte si numarul maxim de cuvinte pe aceeasi linie. Cuvintele sunt secvenţe de caractere despărţite prin unul sau mai multe "spatii albe".
*/

#include<stdio.h>
#include<ctype.h>

int main(void)
{
int inceput=0, current=0, prev=0;
 while((prev=getchar())!=EOF)
 {
 	current = getchar();
 	putchar(current);
 	putchar(prev);
 	
 	//if(isalpha(current) && prev==' ')
 	   
 }

}

































