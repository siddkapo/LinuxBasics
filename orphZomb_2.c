#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int pid = 0;
	pid = fork();
	if(pid == -1)
		perror("Fork\n");
	else if(pid == 0) {
		printf("Child proc %d %d\nps -elf | grep a.out\n", getpid(), getppid());
		system("ps -elf | grep a.out");
		sleep(1);
	}
	else {
		printf("Parent proc %d %d\n", getpid(), getppid());
		sleep(5);
		printf("ps -elf | grep a.out\n");
		system("ps -elf | grep a.out");
		sleep(2);
	}
}
