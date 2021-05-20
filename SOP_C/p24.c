#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int a,b,wynik,i,punkty=0;
	srand(time(NULL));

	printf("przed Toba 20 losowych pytan\n");

	for(i=0;i<20;i++)
	{
		a=rand()%10+1;
		b=rand()%10+1;
		
		printf("%d*%d= ?\n",a,b);
		scanf("%d",&wynik);
		
		if (wynik==a*b) {
			printf("brawo!\n");
			punkty++;
		} else {
			printf("blad, poprawny wynik to %d\n",a*b);
		}
	}
		printf("zdobyles %d punktow na 20 mozliwych\n",punkty);

	if (punkty>=0&&punkty<=4) {
		printf("dostajesz 1\n");
	} else if (punkty>4&&punkty<=8) {
		printf("dostajesz 2\n");
	} else if (punkty>8&&punkty<=12) {
		printf("dostajesz 3\n");
	} else if (punkty>12&&punkty<=16) {
		printf("dostajesz 4\n");
	} else if (punkty>16&&punkty<=20) {
		printf("dostajesz 5\n");
	}
	
	return 0;
}
