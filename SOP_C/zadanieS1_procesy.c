#define _POSIX_SOURCE // Inaczej przy kompilacji wyskakuje warning: implicit declaration of function ‘kill’
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int main() {
	
	int status;
	
	pid_t x, y;

	// Wprowadzam ignorowanie wybranego syngału, żeby przy wysłaniu sygnału do całej grupy procesów
	// nie "zadziałał" on również w odniesieniu do procesu macierzystego; ta instrukcja zostanie
	// zastąpiona w procesach potomnych przez zastosowanie polecenia execl(). 

	if (signal(SIGTSTP, SIG_IGN) == SIG_ERR) {
		perror("Błąd! Funkcja signal ma problem z SIGUSR1");
                exit(1);
        }

	x = fork();

	if (x < 0) {
		printf("Błąd! Nie można utworzyć nowego procesu (potomka).\n");
	}

	if (x == 0) {
		
		printf ("< - - [%u] (proces potomny) - - >\n\n", (int) getpid());
		
		printf ("[%u] Utworzono proces potomny, a jego PID to: %d\n", (int) getpid (), (int) getpid ());
		
		printf ("[%u] Uruchomienie programu \"zadanieS1\" z parametrami 0 i -u2 w procesie potomnym.\n", (int) getpid ());
		
		execl("/home/ubuntu/SOP/pjatk-sop/SOP_C/zadanieS1", "zadanieS1", "0", "-u2", NULL);
		perror("Bląd! Uruchomienie programu nie powiodło się.\n");
		_exit(1);

	} else {

		y  = fork();
        
		if (y < 0) {
                	printf("Błąd! Nie można utworzyć nowego procesu (potomka).\n");
        	}
		
		if (y == 0) {
		
			sleep(1); // Polecenia sleep służą przejrzystości - zachowaniu odpowiedniej kolejności uruchamiania i wyświetlania komend na terminalu.
		
			printf ("\n< - - [%u] (proces potomny) - - >\n\n", (int) getpid());

			printf ("[%u] Utworzono proces potomny, a jego PID to: %d\n", (int) getpid(), (int) getpid());
		
			printf ("[%u] Uruchomienie programu \"zadanieS1\" z parametrami 0 i -u1 w procesie potomnym.\n", (int) getpid());
		
			execl("/home/ubuntu/SOP/pjatk-sop/SOP_C/zadanieS1", "zadanieS1", "0", "-u1", NULL);
	       		perror("Bląd! Uruchomienie programu nie powiodło się.\n");
			_exit(1);
		
		} else {

			sleep(2); 	

			printf ("\n< - - [%u] (proces macierzysty) - - >\n\n", (int) getpid());
		
			printf("[%u] Wysyłanie sygnałów do programów uruchomionych w procesach potomnych.\n", (int) getpid());
			
			if (kill(x, SIGUSR1) == -1) { 
				printf("Błąd! Wysłanie sygnałów (uruchomienie polecenia kill) nie powiodło się.\n");
			}

                	if (kill(y, SIGUSR1) == -1) {
                        	printf("Błąd! Wysłanie sygnałów (uruchomienie polecenia kill) nie powiodło się.\n");
                	}

                	if (kill(0, SIGTSTP) == -1) {
                        	printf("Błąd! Wysłanie sygnałów (uruchomienie polecenia kill) nie powiodło się.\n");
                	}
		
			while (waitpid(x, &status, WNOHANG) == 0 && waitpid(y, &status, WNOHANG) == 0) {
				sleep(1);
			}

			printf("\n< - - Koniec - ->\n");
		}	
	} 

	return 0;
}
