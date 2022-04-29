![GitHub Logo](/extras/images/Success.png)

###### <i>Recent Update on 29/04/2022.</i>
• Finished the project.

###### <i>Old Update on 28/04/2022.</i>
• Started the project.

## Subject:

You can find the subject of this project [here.](https://github.com/Olbrien/42Lisboa-lvl_5_minitalk/blob/main/extras/lvl_5_minitalk.pdf)

## How to run:

First download the repository.


## Useful Links:

[sigaction](https://youtu.be/_1TuZUbCnX0)


## Research:

<code>

Signals:

	A signal is a software generated interrupt that is sent to a process by the OS because
	of when user press ctrl-c or another process tell something to this process.
	There are fix set of signals that can be sent to a process. signal are identified by
	integers.
	Signal number have symbolic names. For example SIGCHLD is number of the signal sent to
	the parent process when child terminates.

	Example:

		/*  Signals in the 1-15 range are defined with their historical numbers.
		For other signals, we use the BSD numbers.
		There are two unallocated signal numbers in the 1-31 range: 7 and 29.
		Signal number 0 is reserved for use as kill(pid, 0), to test whether
		a process exists without sending it a signal.  */

		/* ISO C99 signals.  */
		#define	SIGINT		2	/* Interactive attention signal.  */
		#define	SIGILL		4	/* Illegal instruction.  */
		#define	SIGABRT		6	/* Abnormal termination.  */
		#define	SIGFPE		8	/* Erroneous arithmetic operation.  */
		#define	SIGSEGV		11	/* Invalid access to storage.  */
		#define	SIGTERM		15	/* Termination request.  */

		/* Historical signals specified by POSIX. */
		#define	SIGHUP		1	/* Hangup.  */
		#define	SIGQUIT		3	/* Quit.  */
		#define	SIGTRAP		5	/* Trace/breakpoint trap.  */
		#define	SIGKILL		9	/* Killed.  */
		#define SIGBUS		10	/* Bus error.  */
		#define	SIGSYS		12	/* Bad system call.  */
		#define	SIGPIPE		13	/* Broken pipe.  */
		#define	SIGALRM		14	/* Alarm clock.  */

		/* New(er) POSIX signals (1003.1-2008, 1003.1-2013).  */
		#define	SIGURG		16	/* Urgent data is available at a socket.  */
		#define	SIGSTOP		17	/* Stop, unblockable.  */
		#define	SIGTSTP		18	/* Keyboard stop.  */
		#define	SIGCONT		19	/* Continue.  */
		#define	SIGCHLD		20	/* Child terminated or stopped.  */
		#define	SIGTTIN		21	/* Background read from control terminal.  */
		#define	SIGTTOU		22	/* Background write to control terminal.  */
		#define	SIGPOLL		23	/* Pollable event occurred (System V).  */
		#define	SIGXCPU		24	/* CPU time limit exceeded.  */
		#define	SIGXFSZ		25	/* File size limit exceeded.  */
		#define	SIGVTALRM	26	/* Virtual timer expired.  */
		#define	SIGPROF		27	/* Profiling timer expired.  */
		#define	SIGUSR1		30	/* User-defined signal 1.  */
		#define	SIGUSR2		31	/* User-defined signal 2.  */

		/* Nonstandard signals found in all modern POSIX systems
		(including both BSD and Linux).  */
		#define	SIGWINCH	28	/* Window size change (4.3 BSD, Sun).  */

		/* Archaic names for compatibility.  */
		#define	SIGIO		SIGPOLL	/* I/O now possible (4.2 BSD).  */
		#define	SIGIOT		SIGABRT	/* IOT instruction, abort() on a PDP-11.  */
		#define	SIGCLD		SIGCHLD	/* Old System V name */


	User Defined Signal Handlers

		A process can replace the default signal handler for almost all signals (but not
		SIGKILL) by its user’s own handler function.
		A signal handler function can have any name, but must have return type void and have
		one int parameter.

			void handle_signal(int sig)
			{
				printf("\nsig = %d\n", sig);
				printf("cmd = cntrl + c\n");
				exit(1);
			}

			int main()
			{
				signal(SIGINT, handle_signal);
				while(1)
				{
					printf("Hello Worlda!\n");
					sleep(1);
				}
				return (0);
			}
	
	
	Sending signals via kill()

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


Sigaction:

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

---------------------------------------------------------------------------------------------

SIGUSR1 and SIGUSR2:
	
	These signals are set aside for you to use any way you want.
	They’re useful for simple interprocess communication, if you write a signal handler for
	them in the program that receives the signal.

---------------------------------------------------------------------------------------------

</code>
