#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

int x;

void handler() {
	wait(&x);
	printf("SIGCHLD rec\n");
	sleep(2);
}

int main(int argc, char *argv[]) {
	int pid = 0;
	int x;
	pid = fork();
	if(pid == -1)
		perror("Fork\n");
	else if(pid == 0) {
		printf("Child proc %d %d\nps -elf | grep a.out\n", getpid(), getppid());
		system("ps -elf | grep a.out");
	}
	else {
		printf("Parent proc %d %d\n", getpid(), getppid());
		signal(SIGCHLD, handler);
		sleep(5);
		printf("ps -elf | grep a.out\n");
		system("ps -elf | grep a.out");
	}
	return 0;
}
