#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
	//printf("Jestes w katalogu:\n");
	//execl ("/bin/pwd", "pwd", (char *)0);
	//perror ("Blad uruchamiania execl pwd");
	
	execl("/bin/ls", "-la", (char *)0);
	perror ("Blad uruchamiania execl ls");
	// _exit(1);
	exit(1);
	
	//execlp ("pwd", "pwd", (char *)0);
	//perror ("Blad uruchamiania execlp pwd");
	//execlp ("ls", "-la", (char *)0);
	//perror ("Blad uruchamiania execlp ls");

	return 0;
}
