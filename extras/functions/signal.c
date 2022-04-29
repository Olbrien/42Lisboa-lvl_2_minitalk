#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

void handle_int(int sig)
{
	printf("\n\nsig = %d\n", sig);
	printf("cmd = cntrl + c\n");
	printf("handle interrupt\n");
	exit(1);
}

void handle_abrt(int sig)
{
	printf("\nsig = %d\n", sig);
	printf("handle abort\n");
	exit(1);
}


int main()
{
	pid_t pid = getpid();
	printf("pid = %d\n", pid);

	signal(SIGINT, handle_int);
	signal(SIGABRT, handle_abrt);
	for(int i = 1; i <= 3; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}

	kill(pid, SIGABRT);

	return (0);
}