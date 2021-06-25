#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main () {
	pid_t mother_pid = getpid();
	pid_t child_pid;
	printf ("PID glownego programu: %d\n", (int) mother_pid);
	child_pid = fork ();
	if (child_pid != 0) {
		printf ("to jest proces macierzysty, a jego PID to: %d\n", (int) getpid());
		printf ("PID procesu potomnego: %d\n", (int) child_pid);
	} else {
		printf ("to jest proces potomny, a jego PID to: %d\n", getpid());
	} 
	return 0;
}
