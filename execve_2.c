#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
	char *arg[10];
	char *path = "/bin/ps";
	arg[0] = "ps";
	arg[1] = "-efl";
	arg[2] = NULL;
	int cpid;
	cpid = fork();
	if(cpid == -1)
		perror("ERROR\n");
	else if(cpid == 0) {
		execve(path, arg, NULL);
		perror("ERROR\n");
	}
	else {
		printf("Parent\n");
		exit(0);
	}
	return 0;
}
