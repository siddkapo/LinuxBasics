#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char *path = "/bin/ls";
	char *argVec[10];
	argVec[0] = "ls";
	argVec[1] = NULL;
	execve(path, argVec, NULL);
	perror("ERROR\n");
	return 0;
}
