#include <stdio.h>

int main()
{
	int i;

	printf("liczby nieparzyste z przedzialu 1-100\n");

	for (i=1;i<=100;i++) {

		if(i%2==0) {
			continue;
		}
		printf("%d ",i);
	}

	printf("\n");

	return 0;
}
