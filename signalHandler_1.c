#include<stdlib.h>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void myHandler(int i) {
	printf("Signal received\n");
}

int main() {
	printf("Hello World\n");
	signal(SIGINT, myHandler);
	signal(SIGQUIT, myHandler);
	while(1)
		pause();

	return 0;
}
