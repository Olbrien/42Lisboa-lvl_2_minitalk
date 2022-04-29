#include <unistd.h>
#include <stdio.h>
#define __USE_POSIX 1
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

	struct sigaction sa_int;
	sa_int.sa_handler = &handle_int;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;

	struct sigaction sa_abrt;
	sa_abrt.sa_handler = &handle_abrt;
	sigemptyset(&sa_abrt.sa_mask);
	sa_abrt.sa_flags = 0;

	sigaction(SIGINT, &sa_int, NULL);
	sigaction(SIGABRT, &sa_abrt, NULL);

	for(int i = 1; i <= 3; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}

	kill(pid, SIGABRT);

	return (0);
}