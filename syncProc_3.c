#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int i;

void handler() {
	printf("PID = %d, seq = %d\n", getpid(), i);
}
int main() {
	signal(SIGUSR1, handler);
	int cpid,spm;
	sigset_t set,eset;
	sigemptyset(&set);
	sigemptyset(&eset);
	sigaddset(&set, SIGUSR1);
	
	spm = sigprocmask(SIG_BLOCK, &set, NULL);
	if(spm == -1) {
		perror("ERROR\n");
		return 0;
	}

	cpid = fork();
	if(cpid == -1)
		perror("Error\n");
	else if(cpid == 0) {
		printf("Child PID = %d\n", getpid());
		for(i = 1; i <= 5000; i++) {
			kill(getppid(), SIGUSR1);
			sigsuspend(&eset);
		}
	}
	else {
		printf("Parent PID = %d\n", getpid());
		for(i = 1; i <= 5000; i++) {
			sigsuspend(&eset);
			kill(cpid, SIGUSR1);
		}
	}
	return 0;
}
