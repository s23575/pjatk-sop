#include <stdio.h>

int main()
{
	int i = 0; 
	int j;
	
	printf("Kolejne wprowadzane liczby będą do siebie dodawane.\nAby zakończyć wpisz dowolny znak (inny niż liczba).\n");


	while (scanf("%d", &j) == 1) {
		printf("%d + %d = %d\n", i, j, i+j);
		i = i+j;
	}

	printf("Końcowy wynik to: %d\n", i);
	
	return 0;
}

