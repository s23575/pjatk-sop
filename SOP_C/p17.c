#include <stdio.h>

int main()
{
	int liczba;

	printf("podaj liczbe calkowita\n");
	scanf("%d",&liczba);
	
	if(liczba%2==0) {
		printf("liczba parzysta\n");
	} else {
		printf("liczba nieparzysta\n");
	}
	return 0;
}
