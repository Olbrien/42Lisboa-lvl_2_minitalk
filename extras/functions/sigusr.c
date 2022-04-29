#include <unistd.h>
#include <stdio.h>
#define __USE_POSIX 1
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

void handle_usr1(int sig)
{
	printf("handle usr1\n");	
}

void handle_usr2(int sig)
{
	printf("handle usr2\n");
}

int main()
{
	pid_t pid = getpid();
	printf("pid = %d\n", pid);

	struct sigaction sa_usr1;
	sa_usr1.sa_handler = &handle_usr1;
	sigemptyset(&sa_usr1.sa_mask);
	sa_usr1.sa_flags = 0;

	struct sigaction sa_usr2;
	sa_usr2.sa_handler = &handle_usr2;
	sigemptyset(&sa_usr2.sa_mask);
	sa_usr2.sa_flags = 0;

	sigaction(SIGUSR1, &sa_usr1, NULL);
	sigaction(SIGUSR2, &sa_usr2, NULL);

	while(1)
	{
		sleep(2);
		kill(pid, SIGUSR1);
		sleep(2);
		kill(pid, SIGUSR2);
	}

	return (0);
}