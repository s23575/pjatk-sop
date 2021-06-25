#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main() {

	char command[] = "ls -l";
	system(command);

	return 0;
}
