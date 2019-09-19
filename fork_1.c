#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	int n,i,c = 0;
	scanf("%d",&n);
	pid_t childPid;
	switch(childPid = fork()) {
		case -1:
			exit(0);
		case 0:
			//sleep(5);
			for(i = 2; i < n; i++) {
				if(n % i == 0) {
					c++;
					break;
				}
			}
			if(c == 0)
				printf("Prime\n");
			else
				printf("Not prime\n");
			break;
		default:
			sleep(3);
			break;
	}

	printf("PID = %ld %s Hello World\n", (long)getpid(), (childPid == 0) ? "child" : "parent");
	//sleep(10);
	exit(EXIT_SUCCESS);
	return 0;
}
