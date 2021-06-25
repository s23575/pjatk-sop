#include <stdio.h>
#define TEST "przykład"

int main()

{
	printf("%s\n", TEST);	
	for (int i = 0; i < sizeof(TEST)-1; i++) { //minus 1 dlatego, żeby uniknąć znaku końca tabeli
	
		printf("litera nr %d:\t%c\tascii:\t%d\n", i, TEST[i], TEST[i]);

	} 
	return 0;
}
