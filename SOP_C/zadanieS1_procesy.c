#define _POSIX_SOURCE // Inaczej przy kompilacji wyskakuje warning: implicit declaration of function ‘kill’
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int main(int argc, char* argv[]) {
	
	int status, exit_status;
	
	pid_t mojpid, x, y;
	
	mojpid = getpid();
	
	(x = fork()) && (y = fork());

	if (x < 0 || y < 0) {
		printf("Błąd! Nie można utworzyć nowego procesu (potomka).\n");
	}

	if (x == 0) {
		
		printf ("[%u] Utworzono proces potomny, a jego PID to: %d\n", (int) getpid (), (int) getpid ());
		
		printf ("[%u] Uruchomienie programu \"zadanieS1\" z parametrami 0 i -d w procesie potomnym.\n", (int) getpid ());
		
		if (execl("/home/ubuntu/SOP/pjatk-sop/SOP_C/zadanieS1", "zadanieS1", "0", "-d", NULL) == -1) {
			printf("Błąd! Uruchomienie programu nie powiodło się.\n");
		}
		
		printf("[%u] Zakończony\n", (int) getpid ());

	} else if (y == 0) {
		
		sleep(1); // Polecenia sleep służą przejrzystości - zachowaniu odpowiedniej kolejności uruchamiania i wyświetlania komend na terminalu.

		printf ("[%u] Utworzono proces potomny, a jego PID to: %d\n", (int) getpid(), (int) getpid());
		
		printf ("[%u] Uruchomienie programu \"zadanieS1\" z parametrami 0 i -u1 w procesie potomnym.\n", (int) getpid());
		
		if (execl("/home/ubuntu/SOP/pjatk-sop/SOP_C/zadanieS1", "zadanieS1", "0", "-u1", NULL) == -1) {
			printf("Bląd! Uruchomienie programu nie powiodło się.\n");
		}
		
		printf("[%u] Zakończony\n", (int) getpid());

	}

	else {

		sleep(2); 	

		printf("[%u] Wysyłanie sygnałów do programów uruchomionych w procesach potomnych.\n");	
	
		if (kill(x, SIGUSR1) == -1) { 
			printf("Błąd! Wysłanie sygnałów (uruchomienie polecenia kill) nie powiodło się.\n");
		}
		
		if (kill(x, SIGUSR2) == -1) { 
			printf("Błąd! Wysłanie sygnałów (uruchomienie polecenia kill) nie powiodło się.\n");
		}
		
		if (kill(x, SIGINT) == -1) { 
			printf("Błąd! Wysłanie sygnałów (uruchomienie polecenia kill) nie powiodło się.\n");
		}	
	
		if (kill(y, SIGUSR1) == -1) { 
			printf("Błąd! Wysłanie sygnałów (uruchomienie polecenia kill) nie powiodło się.\n");
		}
		
		while (waitpid(x, &status, WNOHANG) == 0 || waitpid(y, &status, WNOHANG) == 0) {
			sleep(1);
		}
		
		printf("[%u] Zakończony\n", mojpid);
	} 
	return 0;
}
