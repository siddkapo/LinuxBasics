#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint(int signum) {
	printf("SIGINT rec\n");
}

void sigusr(int signum) {
	printf("SIGUSR1 rec\n");
}

int main() {
	printf("Hello World\n");
	signal(SIGINT, sigint);
	signal(SIGUSR1, sigusr);
	sigset_t sigSet;
	sigemptyset(&sigSet);
	sigaddset(&sigSet, SIGINT);
	sigaddset(&sigSet, SIGUSR1);

	int ret = sigprocmask(SIG_BLOCK, &sigSet, NULL);
	if(ret == -1)
		perror("Error\n");
	sigset_t wait;
	sleep(10);
	raise(SIGINT);
	sigpending(&wait);
	if(sigismember(&wait, SIGINT))
		printf("SIGINT pending\n");
	if(sigismember(&wait, SIGUSR1))
		printf("SIGUSR1 pending\n");
	ret = sigprocmask(SIG_UNBLOCK, &sigSet, NULL);
	if(ret == -1)
		perror("Error 2\n");
	return 0;
}
