#include <stdio.h>

void wyp_licz(int num);

int main()
{
	int liczba;

	printf("podaj liczbe calkowita\n");

	scanf("%d",&liczba);

	wyp_licz(liczba);

	return 0;
}

void wyp_licz(int num)
{
	printf("podana liczba wynosi %d\n",num);
}
