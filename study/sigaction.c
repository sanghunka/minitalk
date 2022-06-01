#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>


void handler(int num)
{
	write(STDOUT_FILENO, "I won't die\n", 13);
}


int main()
{
	struct sigaction sa;
	sa.sa_handler = handler;
	
	sigaction(SIGINT, &sa, NULL);

	while (1)
	{
		printf("Wasting YC %d\n", getpid());
		sleep(1);
	}
}
