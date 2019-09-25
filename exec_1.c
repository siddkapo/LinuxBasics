#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("Before execve %d\n", getpid());
	char *argVec[10];
	char *path = "/home/siddharth/Desktop/LinTut/run";
	argVec[0] = "run";
	argVec[1] = NULL;
	execve(path, argVec, NULL);
	perror("Error");
	return 0;
}
