#include <stdio.h>
#include <stdbool.h>
//#include <stdlib.h>

int main()
{
	int i, a, b;
	bool error = false;

	
	while (true) {
		printf("Opcje do wyboru:\n\t1 - dodawanie,\n\t2 - odejmowanie,\n\t3 - mnożenie,\n\t4 - dzielenie;\nAby zakończyć wpisz dowolny znak (inny niż liczba).\n");
		
		printf("Wybierz opcję: ");
		if (scanf("%d", &i) != true) {
			break;
		} else if (i < 1 || i > 4) {
			error = true;
			goto errorhandler;
		}
		
		printf("\n");

		printf("Podaj liczbę a: ");
		if (scanf("%d", &a) != true) {
			while ( (a = getchar()) != '\n' && a != EOF ) { } // "Wyczyszczenie" scanf(), żeby uniknąć błędu w kolejnej iteracji pętli głównej.
			error = true;
			goto errorhandler;
		}

		printf("Podaj liczbę b: ");
		if (scanf("%d", &b) != true) {
			while ( (b = getchar()) != '\n' && b != EOF ) { } // "Wyczyszczenie" scanf(), żeby uniknąć błędu w kolejnej iteracji pętli głównej.
			error = true;
			goto errorhandler;
		}

		printf("\n");

		switch (i) {
			case 1:
				printf("%d + %d = %d", a, b, a + b);
				break;
			case 2:
				printf("%d - %d = %d", a, b, a - b);
				break;
			case 3:
				printf("%d * %d = %d", a, b, a * b);
				break;
			case 4:
				printf("%d / %d = %lf", a, b, (double) a / b);
				break;	
		}

		printf("\n");

		errorhandler:
			if (error == true) {
				printf("Wystąpił błąd; spróbuj jeszcze raz.\n");
				error = false;
			}
		printf("\n");
	}
	return 0;
}

