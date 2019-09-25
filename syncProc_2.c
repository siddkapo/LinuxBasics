#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int i = 0;

void handler(int signum) {
	printf("PID = %d ; seq = %d\n", getpid(), i);
}

int main() {

	pid_t childpid;
	signal(SIGUSR1, handler);
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigprocmask(SIG_BLOCK, &set, NULL);

	childpid = fork();
	if(childpid == -1)
		perror("Error\n");
	else if(childpid == 0) {
		printf("Child PID = %d\n", getpid());
		for(i = 1; i <= 5000; i++) {
			sigprocmask(SIG_UNBLOCK, &set, NULL);
			kill(getppid(), SIGUSR1);
			pause();
			//sigprocmask(SIG_BLOCK, &set, NULL);
		}
	}
	else {
		printf("Parent PID = %d\n", getpid());
		for(i = 1; i <= 5000; i++) {
			sigprocmask(SIG_UNBLOCK, &set, NULL);
			kill(childpid, SIGUSR1);
			pause();
			//sigprocmask(SIG_BLOCK, &set, NULL);
		}
	}

	return 0;
}
