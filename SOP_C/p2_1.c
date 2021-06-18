#include <stdio.h>
#include <unistd.h>

int main () { 
	printf ("PID: %d\n", (int) getpid ()); 
	printf ("PPID: %d\n", (int) getppid ());
       	printf ("UID: %d\n", (int) getuid());
	printf ("eUID: %d\n", (int) geteuid());
	printf ("GID: %d\n", (int) getgid());
	printf ("eGID: %d\n", (int) getegid());
	return 0; 
}
