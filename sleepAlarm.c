#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigHandler() {
	printf("Alarm over\n");
}

int main() {
	alarm(5);	
	//pause();
	signal(SIGALRM, sigHandler);
	pause();
	return 0;
}
