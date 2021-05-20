#include <stdio.h>

int main()
{
	float w,l,h;
	
	printf("jednostki musza byc zgodne!\n");
	
	printf("podaj szerokosc prostopadloscianu\n");
	scanf("%f",&w);
	
	printf("podaj dlugosc prostopadloscianu\n");
	scanf("%f",&l);
	
	printf("podaj wysokosc prostopadloscianu\n");
	scanf("%f",&h);
	
	printf("objetosc wynosi %f j^3\n",w*l*h);

	return 0;
}
