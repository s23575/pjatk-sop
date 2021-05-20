#include <stdio.h>

int main()
{
	float a,b;
	int opcja;

	printf("podaj liczbe a\n");
	scanf("%f",&a);

	printf("podaj liczbe b\n");
	scanf("%f",&b);

	printf("wybierz operacje:\n1- suma, 2- iloczyn\n");
	scanf("%d",&opcja);
	
	if (opcja==1) {
		printf("suma wynosi %f\n",a+b);
	} else if (opcja==2) {
		printf("iloczyn wynosi %f\n",a*b);
	}

	return 0;
}
