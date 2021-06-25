#include <stdio.h>

int main()
{
	float l1,l2;
	char c[5];
	
	printf("podaj 1 liczbe\n"); 
	scanf("%f",&l1);
	
	printf("podaj 2 liczbe\n"); 
	scanf("%f",&l2);
	
	printf("suma: %f\n",l1+l2);

	printf("a teraz podaj string\n");
	scanf("%5s", &c[0]);
	printf("string: %s\n", c);
	
	return 0;
}
