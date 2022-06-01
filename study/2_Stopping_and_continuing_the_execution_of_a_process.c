#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char **argv)
{
	printf("start: %d\n", getpid());
	int pid = fork();
	printf("pid: %d\n", pid);
	
	if (pid == -1)
	{
		return 1;
	}

	if (pid == 0)
	{
		printf("if: %d\n", getpid());
		while (1)
		{
			printf("some text goes here\n");
			printf("%d\n", getpid());
			usleep(50000);
		}
	}
	else
	{
		kill(pid, SIGSTOP);
		int t;
		do {
			printf("Time in seconds for execution: ");
			scanf("%d", &t);

			if (t > 0)
			{
				kill(pid, SIGCONT);
				sleep(t);
				kill(pid, SIGSTOP);
			}
			
		} while (t > 0);

		printf("else: %d\n", getpid());

		kill(pid, SIGKILL);
		wait(NULL);
	}

	return (0);
}