#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void handle_sigtstp(int sig)
{
	printf("stop not allowed\n");
}

void handle_sigcont(int sig)
{
	printf("Input nuber: ");
	fflush(stdout);
}

int main(int argc, char **argv)
{
	struct sigaction sa;
	// sa.sa_handler = &handle_sigtstp;
	sa.sa_handler = &handle_sigcont;
	sa.sa_flags = SA_RESTART;
	// sigaction(SIGTSTP, &sa, NULL);
	sigaction(SIGCONT, &sa, NULL);

	int x;
	printf("Input nuber: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x , x * 5);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	signal(SIGTSTP, &handle_sigtstp);

// 	int x;
// 	printf("Input nuber: ");
// 	scanf("%d", &x);
// 	printf("Result %d * 5 = %d\n", x , x * 5);
// 	return (0);
// }