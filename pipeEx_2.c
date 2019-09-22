#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int myPipe1[2];
	int myPipe2[2];
	pipe(myPipe1);
	pipe(myPipe2);
	char arr[100];
	int cPid = fork();
	if(cPid == -1)
		perror("Error\n");
	else if(cPid == 0) {
		while(1) {
			read(myPipe1[0], arr, 100);
			int i;
			printf("Child %d:\n", getpid());
			for(i = 0; i < 100; i++) {
				if(arr[i] >= 'a' && arr[i] <='z')
					arr[i] -= 32;
			}
			write(myPipe2[1], arr, 100);
		}
	}
	else {
		while(1) {
			scanf("%s", arr);
			write(myPipe1[1], arr, 100);
			read(myPipe2[0], arr ,100);
			printf("Parent %d: %s\n", getpid(), arr);
		}
	}
	return 0;
}
