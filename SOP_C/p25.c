#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int a,b,ilosc=0,punkty=0,wynik,opcja;
	srand(time(NULL));
	
	poczatek:
		a=rand()%100+1;
		b=rand()%100+1;
		
		printf("%d+%d= ?\n",a,b);
		scanf("%d",&wynik);
		
		if(wynik==a+b) {
			printf("brawo!\n");
			punkty++;
		} else {
			printf("blad, poprawny wynik to %d\n",a+b);
		}
		ilosc++;
		
		printf("kontynuowac?1- tak, 2- koniec\n");
		scanf("%d",&opcja);

		if(opcja==1) {
			goto poczatek;
		}

		if(opcja==2) {
			printf("Twoj wynik to %d/%d\n",punkty,ilosc);
			exit(1);
		}		
	return 0;
}
