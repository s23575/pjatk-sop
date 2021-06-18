#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/errno.h> 
#include <ctype.h>
#include <string.h>

void default_handler(int sig_num);
void ignore(int sig_num);
void user_handler_1(int sig_num);
void user_handler_2(int sig_num);

void my_SIGHAND1();
void my_SIGHAND2();

int main(int argc, char *argv[]) {
	
	//< - - Pobieranie i sprawdzanie argumentów - - >
	
	const char* options = "-d - obsługa domyślna sygnału(ów);\n\
-i - ignorowanie sygnału(ów);\n\
-u1 - obsługa użytkownika #1;\n\
-u2 - obsługa użytkownika #2.\n";
	
	int sig_num;
	char* option;
	
	if (argc < 3) {
	
		printf("Błąd! Nie podano żadnych argumentów lub podano ich zbyt mało.\n\
Podaj numer sygnału do obsługi (lub 0, aby obsłużyć domyślne sygnały) oraz wybrany sposób obsługi sygnału(ów):\n\
%s", options);
		return 0;

	} else {
		
		sig_num = atoi(argv[1]);
		option = argv[2];
	
		if (sig_num < 0) {
			printf("Błąd! Podano błędny numer sygnału do obsługi.\n\
Podaj numer sygnału do obsługi (lub 0, aby obsłużyć domyślne sygnały).\n");
			return 0;
		}
		
		if (strcmp(option,"-d") && strcmp(option,"-i") && strcmp(option,"-u1") && strcmp(option,"-u2")) {		
				printf("Błąd! Nie podano sposobu obsługi sygnału(ów).\n\
Podaj wybrany sposób obsługi sygnału(ów):\n\
%s", options);
			return 0;	
		}
	}

	//< - - Obsługa sygnałów - - >

	printf("PID procesu: %d\n",(int) getpid()); 
	printf("Stygnał lub sygnały (0 - domyślne) do obsługi: %d\n",sig_num); 

	
	if (!strcmp(option,"-d")) {
			default_handler(sig_num);
	}
	
	if (!strcmp(option,"-i")) {
			ignore(sig_num);
	}
	
	if (!strcmp(option,"-u1")) {
			user_handler_1(sig_num);
	}

	if (!strcmp(option,"-u2")) {
			user_handler_2(sig_num);
	}

	if (pause() < 0) {
		perror("Błąd! Sygnał nie powoduje zakonczenia procesu.");
		exit(EXIT_FAILURE);
	}

	return 0;
}

void default_handler(int sig_num) {
	printf("Program odpowie domyślnie na sygnał.\n");
	
	if (sig_num > 0) {
		
		if (signal(sig_num, SIG_DFL) == SIG_ERR) {
		 perror("Błąd! Funkcja signal ma problem z wybranym sygnałem");
		 exit(EXIT_FAILURE);
		}
		
	} else {
	
		if (signal(SIGQUIT,SIG_DFL) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGQUIT.");
			exit(EXIT_FAILURE);
		}
		if (signal(SIGINT,SIG_DFL) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGINT");
			exit(EXIT_FAILURE);
		}
		if (signal(SIGUSR1,SIG_DFL) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGUSR1.");
			exit(EXIT_FAILURE);
		}
		if (signal(SIGTSTP,SIG_DFL) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGTSTP.");
			exit(EXIT_FAILURE);
		}
		
	}
}

void ignore(int sig_num) {
	printf("Program zignoruje sygnał (jeżeli będzie to możliwe).\n");

	if (sig_num > 0) {
		
		if (signal(sig_num, SIG_IGN) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z wybranym sygnałem.");
			exit(EXIT_FAILURE);
		}
		
	} else {
	
		if (signal(SIGQUIT, SIG_IGN) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGQUIT.");
			exit(EXIT_FAILURE);
		}
		
		if (signal(SIGINT, SIG_IGN) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGINT.");
			exit(EXIT_FAILURE);
		}
		
		if (signal(SIGUSR1, SIG_IGN) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGUSR1.");
			exit(EXIT_FAILURE);
		}
		
		if (signal(SIGTSTP, SIG_IGN) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGTSTP.");
			exit(EXIT_FAILURE);
		}
	}	
}

void my_SIGHAND1() {
	printf("Obsługa sygnału określona przez użytkownika #1\n");
	exit(EXIT_SUCCESS);
}

void my_SIGHAND2() {
	printf("Obsługa sygnału określona przez użytkownika #2\n");
	exit(EXIT_SUCCESS);
}

void user_handler_1(int sig_num) {

	printf("Program obsłuży sygnał zgodnie z obsługą określoną przez użytkownika #1.\n");

	if (sig_num > 0) {
		
		if (signal(sig_num, my_SIGHAND1) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z wybranym sygnałem.");
			exit(EXIT_FAILURE);
		}
		
	} else {
	
		if (signal(SIGQUIT, my_SIGHAND1) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGQUIT.");
			exit(EXIT_FAILURE);
		}
		
		if (signal(SIGINT, my_SIGHAND1) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGINT.");
			exit(EXIT_FAILURE);
		}
		
		if (signal(SIGUSR1, my_SIGHAND1) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGUSR1.");
			exit(EXIT_FAILURE);
		}
		
		if (signal(SIGTSTP, my_SIGHAND1) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGTSTP.");
			exit(EXIT_FAILURE);
		}
	}
}

void user_handler_2(int sig_num) {

	printf("Program obsłuży sygnał zgodnie z obsługą określoną przez użytkownika #2.\n");

	if (sig_num > 0) {
		
		if (signal(sig_num, my_SIGHAND2) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z wybranym sygnałem.");
			exit(EXIT_FAILURE);
		}
		
	} else {
	
		if (signal(SIGQUIT, my_SIGHAND2) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGQUIT.");
			exit(EXIT_FAILURE);
		}
		
		if (signal(SIGINT, my_SIGHAND1) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGINT.");
			exit(EXIT_FAILURE);
		}
		
		if (signal(SIGUSR1, my_SIGHAND2) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGUSR1.");
			exit(EXIT_FAILURE);
		}
		
		if (signal(SIGTSTP, my_SIGHAND2) == SIG_ERR) {
			perror("Błąd! Funkcja signal ma problem z SIGTSTP.");
			exit(EXIT_FAILURE);
		}
	}
}
