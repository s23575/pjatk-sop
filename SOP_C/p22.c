#include <stdio.h>
#include <math.h>

int main()
{
	float kat;
	int opcja;

	printf("ile stopni ma kat?\n");
	scanf("%f",&kat);

	printf("1- sinus, 2- cosinus\n");
	scanf("%d",&opcja);
	
	switch (opcja) {
		case 1:
			printf("sin %f stopni=%.3f\n", kat, sin(kat/180*M_PI));
			break;
		case 2:
			printf("cos %f stopni=%.3f\n", kat, cos(kat/180*M_PI));
			break;
		default:
			printf("blad\n");
	}
	
	return 0;
}

