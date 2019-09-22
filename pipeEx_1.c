#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int myPipe1[2];
	int myPipe2[2];
	char arr[1000];
	pipe(myPipe1);
	pipe(myPipe2);
	int childPid = fork();
	if(childPid == -1)
		perror("Child Error\n");
	else if(childPid == 0) {
		while(1) {
			scanf("%s", arr);
			write(myPipe2[1], arr, 100);
			read(myPipe1[0], arr, 100);
			printf("Parent %d: %s\n", getppid(), arr);
		}
	}
	else {
		while(1) {
			read(myPipe2[0], arr, 100);
			printf("Child: %s\n", arr);
			scanf("%s", arr);
			write(myPipe1[1], arr, 100);
		}
	}
	return 0;
}
