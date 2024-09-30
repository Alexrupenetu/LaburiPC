#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//LABORATOR 8 + 9 CV: CARACTERE + SIRURI

/*1.)Scrieți un program, folosind getchar() și putchar() prin care se numără cuvintele de la stdint. Se consideră un cuvânt ca fiind o secvență de litere mici și/sau mari care despărțite prin unul sau mai multe spații, tab-uri, linii noi și EOF. Testarea se va face atât clasic prin scriere la stdin cât și prin redirectare cu un fișier text realizat inainte ca și caz de test catre intrarea standard a programului*/

void p1()
{
	char ch;
	int cuvant = 0, contor=0;
	while((ch = getchar())!=EOF)
	{
		if(isalpha(ch))
		{
			cuvant = 1;
		}
		else
		{
		if(cuvant!=0)
		{
			cuvant = 0;
			contor ++;
		}
		}	
	}
	if(cuvant!=0)
		contor++;
	printf("In fisier sunt %d cuvinte\n", contor);
}

/*2/)Scrieți un program, folosind getchar() și putchar(), care, primind la stdin redirectat un fișier ce conține un cod C, va printa la stdout același fișier dar fără comentarii. Practic, programul va elimina comentariile din fișierul C primit prin redirectare de stdin și va printa rezultatul la stdout. */

void p2()
{
	char ch;
	int comentariu=0;
	while((ch = getchar())!=EOF)
	{	
		if(comentariu == 0)
			{
			if(ch!='/')
				putchar(ch);
			else
				comentariu = 1;
			}
		else
		{
			if(ch == '\n')
				{
				comentariu = 0;
				putchar(ch);
				}
		}
		
	}
}

/*3.)Scrieți un program, folosind getchar() pentru citire, care, primind la stdin redirectat un fișier text va tipari la iesirea standard histograma literelor, adica distributia in procente a literelor din fisier. Se considera in calcul doar litere mari si litere mici. Programul va printa pe cate un rand litera si procentajul de aparitie.*/

void p3()
{
	char c; float procentaj;
	int array[30]={0}, index, contor=0;
	
	while((c = getchar())!=EOF)
	{
		if(isalpha(c))
		{
			index = c - 'a';
			array[index]++;
			contor++;
		}
	}
	printf("\n");
	for(int i=0; i<26; i++)
		{
			char litera = 'a' + i;
			if(array[i]!=0)
			{
			procentaj = array[i] * 100 / (float)contor;
			printf("%c - %.2f%%\n", litera, procentaj);
			}
		}
}

/*4.)Scrieți un program, folosind getchar() si putchar() care, primind la stdin un fișier text va tipari la iesirea standard acelasi fisier text dar va schimba literele mari intalnite in fisier in litere mici iar cele mici in litere mari.*/

void p4()
{
	char ch, c;
	
	while((ch = getchar())!=EOF)
	{
	if(isalpha(ch))
	{
		if(isupper(ch))
		{
			c = tolower(ch);
			putchar(c);
		}
		else if(islower(ch))
		{
			c = toupper(ch);
			putchar(c);
		}
	}
	else
	putchar(ch);
	}
}

/*5.)Scrieti un program care numără caracterele, cuvintele şi liniile citite de la intrarea standard, pana la sfarsitul acesteia. Cuvintele sunt secvenţe de caractere despărţite prin unul sau mai multe "spatii albe". Precizări O linie se numără doar când e încheiată cu '\n'. Programul va tipări la ieşire numărul de linii, cuvinte, şi caractere, aliniate la dreapta pe un câmp de lăţime 7 (se poate face cu formatul %7d), şi separate prin câte un spaţiu. Pentru comparaţie, folosiţi programul UNIX wc (word count).*/

void p5()
{
	char ch;
	int cuvinte=0, cuv=0, linii=0, caractere=0;
	
	while((ch=getchar())!=EOF)
	{
		if(ch == '\n')
			linii++;
		if(isalpha(ch))
		{
			cuv = 1;
		}
		else
		{
		if(cuv!=0)
		{
			cuv = 0;
			cuvinte++;
		}
		}
		caractere++;
	}
	
	if(cuv)
	 cuvinte++;	
		
	printf("%7d\n%7d\n%7d\n",linii, cuvinte, caractere);
}

//la 6 e same shit dar numeri doar liniile si cuvintele

/*7.)Scrieti un program care tipareste la iesire textul citit de la intrarea standard, modificat astfel incat orice litera de la inceputul unui cuvant e transcrisa ca litera mare. La sfarsit, programul va tipari numarul total de cuvinte si numarul maxim de cuvinte pe aceeasi linie. Cuvintele sunt secvenţe de caractere despărţite prin unul sau mai multe "spatii albe".*/

void p7()
{
	char cur_ch, prev_ch, after_ch, ch;
	
	prev_ch = getchar(); 
	if(isalpha(prev_ch))
		{
		ch = toupper(prev_ch);
		putchar(ch);
		}
	else
		putchar(prev_ch);
	cur_ch = getchar(); 
	while((ch = getchar())!=EOF)
	{
		after_ch = ch;
		if(prev_ch==' ' && isalpha(cur_ch) && isalpha(after_ch))
			{
			ch = toupper(cur_ch);
			putchar(ch);
			}
		else
		  	putchar(cur_ch);
		prev_ch = cur_ch;
		cur_ch = after_ch;	
	}
}

/*8.)Un fișier html conține o serie de tag-uri, adică cuvinte cheie între simbolurile < și >.
Aceste tag-uri (etichete) pot fi de două feluri:
- pereche (de exemplu <head>-început și </head>-încheiere)
- singulare (de exemplu <br>)
Se cere să se citească de la stdin un fișier html, folosind redirectare și funcția getchar, și să se numere câte tag-uri de început și câte tag-uri de încheiere conține fișierul.*/

void p8()
{
	char ch;
	int tag=0, start=0, end=0; // ?!?!?!??!?!
	
	
	while((ch = getchar())!=EOF)
	{
		if(ch == '<')
			tag = 1;
		else if(ch == '>')
			tag = 0;
		else if(tag!=0)
		{
			if(ch == '/')
				end++;
			else if(ch !=' ' && ch!='\n')
				start++;
		}
	}
	
	printf("start - %d\n end - %d", start, end);
}

//SIRURI DE CARACTERE

//Să se citească o linie de la tastatură. Linia conține cuvinte care sunt formate doar din litere, cuvintele fiind despărțite prin orice alte caractere ce nu sunt litere. Să se capitalizeze prima literă din fiecare cuvânt și să se afișeze șirul rezultat 
void pb1()
{
	char linie[105];
	fgets(linie, 100, stdin);
	int len;
	len = strlen(linie);
	int i=0;
	linie[i] = toupper(linie[i]);
	for(i=1; i<len; i++)
		if(isalpha(linie[i-1])==0 && isalpha(linie[i])!=0)
			linie[i]=toupper(linie[i]);
			
	printf("%s", linie);
}

//Se va citi un n<=10. Se vor citi apoi pe rând n nume. Se cere ca în final să fie afișat numele cel mai lung și lungimea sa
void pb2()
{
	char nume[10][100], nume_max[100];
	int n, len, max=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		{
		scanf("%s", nume[i]);
		len = strlen(nume[i]);
			if(len>max)
			{
			max = len;
			strcpy(nume_max, nume[i]);
			}
		}
	printf("Numele max este %s\n", nume_max);
}

//Se citește un n<=10 și apoi n nume de persoane, fiecare nume putând apărea de mai multe ori. Să se afișeze de câte ori apare fiecare nume

typedef struct
{
char Nume[50];
int frecv;
}Data;

Data vector[11];

void pb3()
{
	int n;
	char name[10][50];
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
		scanf("%s", name[i]);
		
	for(int i=0; i<11; i++)
		vector[i].frecv=0;
		
	for (int i = 0; i < n; i++) {
        int gasit = 0;
        for (int j = 0; j < 11; j++) {
            if (strcmp(name[i], vector[j].Nume) == 0) {
                vector[j].frecv++;
                gasit = 1;
                break;
            }
        }

        if (!gasit) {
            for (int j = 0; j < 11; j++) {
                if (vector[j].frecv == 0) {
                    strcpy(vector[j].Nume, name[i]);
                    vector[j].frecv = 1;
                    break;
                }
            }
        }
    }

	for(int i=0; i<n; i++)
		if(vector[i].frecv!=0)
			printf("%s - %d\n", vector[i].Nume, vector[i].frecv);
}

// 4.)Se citește un text care este alcătuit doar din litere. Să se afișeze pentru fiecare literă de câte ori apare în text

void pb4()
{
	int frecv[30] = {0};
	char text[100];
	fgets(text, 100, stdin);
	int len, index;
	len = strlen(text);
	
	for(int i=0; i<len; i++)
	{
		index = text[i] - 'a';
		frecv[index]++;
	}
	
	for(int i=0; i<27; i++)
		if(frecv[i]!=0)
			{
			char litera = 'a' + i;
			printf("%c-%d\n", litera, frecv[i]);
			}
}

/*5.)Se citește n din intervalul [3,10] și apoi n nume de persoane. Să se concateneze primele n-1 nume folosind „, ”, ultimul nume cu „ si ”, iar apoi să se adauge „invata.”. Să se afișeze propoziția rezultată.
Exemplu: n=3, numele: Ion Ana Maria
Propoziție rezultata: Ion, Ana și Maria invata.*/

void pb5()
{
	int n;
	char nume[11][50];
	char string[300]="";
	
	scanf("%d", &n);
	
	for(int i=0; i<n-1; i++)
		{
		scanf("%s", nume[i]);
		strcat(string, nume[i]);
		if(i!=n-2)
		strcat(string, ", ");
		}
	strcat(string, " si ");
	scanf("%s", nume[n-1]);
	strcat(string, nume[n-1]);
	strcat(string, " invata");
	
	printf("%s\n", string);
		
}

/*6.)Se va citi un n<=10. Se vor citi apoi n produse, fiecare definit prin nume (un șir de caractere), cantitate (real) și preț unitar (real). Unele produse pot să fie date de mai multe ori, cu valori diferite. Să se calculeze pentru fiecare produs cantitatea și prețul total, iar în final să se calculeze și prețul global pentru toate produsele.*/

typedef struct
{
char nume[50];
float cantitate;
float pret;
}prod;

prod produs[11];

void pb6()
{
	int n;
	float suma_totala=0;
	scanf("%d", &n);
	
	for(int i=0; i<11; i++)
		{
		produs[i].pret=0;
		produs[i].cantitate=0;
		}
	for(int i=0; i<n; i++)
		{
		scanf("%s %g %g", produs[i].nume, &produs[i].cantitate, &produs[i].pret);
		}
		
	char NUME[11][50]; int index=0;
	
	for(int i=0; i<n; i++)
		{
			int gasit = 0;
			for(int j=0; j<index; j++)
			 	if(strcmp(NUME[j], produs[i].nume)==0)
					gasit = 1;
			if(gasit == 0)
				{
				strcpy(NUME[index], produs[i].nume);
				index++;
				}
		}
		
	for(int i=0; i<index; i++)
	{
		printf("%s: ", NUME[i]);
		float cant=0, pret_total=0;
		
		for(int j=0; j<n; j++)
			if(strcmp(NUME[i], produs[j].nume)==0)
			{
				cant += produs[j].cantitate;
				pret_total += produs[j].pret * produs[j].cantitate;
			}
		printf("%g %g\n", cant, pret_total);
		suma_totala += pret_total;
	}
	
	printf("Pret Global: %g", suma_totala);

}

/*7.)Sa se realizeze o implementare proprie a functiilor standard de prelucrare de string-uri cum ar fi: strcmp, strcpy, strstr, strchr, strcat, strncmp, strncpy, strncat, atoi, strtol (fara parametrul char **endptr). Se va realiza atat o implementare ce foloseste operatorul de indexare in tablou cat si o implementare ce foloseste doar pointeri si aritmetica cu pointeri fara a folosi in aceasta si operatorul de indexare.*/

/*  8.) Sa se scrie o functie cu urmatorul antet:

uint32_t upper_sub_string(char *str, const char *substr);

Pentru fiecare aparitie a string-ului substr in string-ul str se va modifica ca acest string din str sa fie transpus in litere mari (upper-case) Functia va returna numarul de aparitii.

Exemplu:

char s1[] = "Acesta este un string si stringul este terminat cu 0x00";
char s2[] = "string";
int r = upper_sub_string(s1, s2);

s1 devine "Acesta este un STRING si STRINGul este terminat cu 0x00";
s2 ramane neschimbat
r devine 2*/

void pb8(char *str, const char *substr)
{
	char *p;
	int len=strlen(substr);
	while(strstr(str, substr))
	{
		p = strstr(str, substr);
		while(str<p)
		{
		printf("%c", *str);
		str++;
		}
		while(str<p+len)
		{
		printf("%c",toupper(*str));
		str++;
		}	
	}
	printf("%s", str);  //nu returneaza nr de aparitii oops	
}
int main(void)
{
	pb8("Acesta este un string si stringul este terminat cu 0x00", "string");
}
































