#include <stdio.h>

int main()
{
	int i; 

	do {
		printf("jaka jest tajna liczba?\n");
		scanf("%d",&i); 
	} while (i!=6);

	printf("zezwalam na dostep\n");

	return 0;
}
