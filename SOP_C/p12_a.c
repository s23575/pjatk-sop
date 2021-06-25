#include <stdio.h>

int main()

{
	char test[]="przykład";
	printf("%s\n", test);	
	for (int i = 0; i < sizeof(test)-1; i++) { //minus 1 dlatego, żeby uniknąć znaku końca tabeli
	
		printf("litera nr %d:\t%c\tascii:\t%d\n", i, test[i], test[i]);

	} 
	return 0;
}
