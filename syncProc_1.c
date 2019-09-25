#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int i = 0;
void handler(int signum) {
	printf("SIGUSR1 rec %d %d\n", getpid(), i);
}

int main() {
	pid_t childPid;
	signal(SIGUSR1, handler);
	childPid = fork();

	if(childPid == -1)
		perror("Error\n");
	else if(childPid == 0) {
		printf("Child\n");
		for(i = 1; i <= 5000; i++) {
			kill(getppid(), SIGUSR1);
			pause();
		}
	}
	else {
		printf("Parent\n");
		for(i = 1; i <= 5000; i++) {
			pause();
			kill(childPid, SIGUSR1);
		}
	}
	return 0;
}
