#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
	int status, exit_status;
	pid_t pid = fork();
	if (pid < 0) {
		printf("ERROR! Nie można utworzyć nowego procesu\n");
	}
	if (pid == 0) //tutaj wejdzie tylko jako potomek
	{
		printf("Potomek (PID: %d) uśpiony...\n", getpid());
		sleep(5);
		exit(0); //wyjście z potomka
	}
	while (waitpid(pid, &status, WNOHANG) == 0) //tutaj tylko jako rodzic
	{
		printf("Czekam na zakończenie potomka...\n");
		sleep(1);
	}
	exit_status = WEXITSTATUS(status); //wyciągniecie wartości ze zwracanej przez waitpid
	printf("Potomek (PID: %d) zakończył działanie zwracając %d\n", pid, exit_status);
	return 0;
}
