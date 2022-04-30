![GitHub Logo](/extras/images/Success.png)

###### <i>Recent Update on 30/04/2022.</i>
• Finished the project.

###### <i>Old Update on 28/04/2022.</i>
• Started the project.

## Subject:

You can find the subject of this project [here.](https://github.com/Olbrien/42Lisboa-lvl_5_minitalk/blob/main/extras/lvl_5_minitalk.pdf)

## How to run:

Download the repository.

On minitalk folder type "make" to compile the project. \
You'll get two binaries inside the binaries folder:
- server
- client

You first need to start the server binary by doing:\
`./server`\
It will give you the Process ID.

Then you need to start the client with two arguments, first the server
Process ID and the message you want to send:
`./client 55123 "Hey There Partner. Hi Bill ♠♠♠♠!"`

The server will get the message, and it will send back to the client
saying it received it!


## Useful Links:

[sigaction video](https://youtu.be/_1TuZUbCnX0)\
[sigaction man](https://man7.org/linux/man-pages/man2/sigaction.2.html)

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

SIGUSR1 and SIGUSR2:

	These signals are set aside for you to use any way you want.
	They’re useful for simple interprocess communication, if you write a signal handler for
	them in the program that receives the signal.

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


Kill:

	The kill() system call can be used to send any signal to any process group or process.

		int kill(pid_t pid, int sig);

---------------------------------------------------------------------------------------------

Bitwise Operators:

	Let's take the character 'Z'.
	It's Ascii code in decimal is 90.

	90 in binary is:

		128    64    32    16     8     4     2     1

		2^7   2^6   2^5   2^4   2^3   2^2   2^1   2^0
	-----------------------------------------------------
		 0     1     0     1      1     0     1     0



		(<<) Left Bit Shift:

			Z = Z << 2;

				Z in binary is: 01011010

				01011010 becomes 01101000

				Adds 2 zeros on the right, removes first 2 bits.

				01101000 = 104
				Decimal 104 is the character 'h'.

			int main()
			{
				char Z = 'Z';
				printf("%c\n", Z);

				Z = Z << 2;
				printf("%c\n", Z);
			}

			Output: Z
					h


		(>>) Right Bit Shift:

			Z = Z >> 1;

				Z in binary is: 01011010

				01011010 becomes 00101101

				Adds 1 zeros on the left, removes last 1 bits.

				00101101 = 45
				Decimal 45 is the character '-'.

			int main()
			{
				char Z = 'Z';
				printf("%c\n", Z);

				Z = Z >> 1;
				printf("%c\n", Z);
			}

			Output: Z
					-


		(&) Bit-wise AND:

			Z & x

				Z in binary is: 01011010
				x in binary is: 01111000

				Returns a 1 in each bit position for which the corresponding bits of
				both operands are 1's.

						01011010
						01111000
				      ------------
						01011000

				01011000 = 88
				Decimal 88 is the character 'X'.

			int main()
			{
				char Z = 'Z';
				char x = 'x';
				char result;

				result = Z & x;
				printf("%c\n", result);
			}

			Output: X


		(|) Bit-wise OR:

			Z | x

				Z in binary is: 01011010
				x in binary is: 01111000

				Returns a 1 in each bit position for which the corresponding bits of
				either or both operands are 1s.

						01011010
						01111000
				      ------------
						01111010

				01111010 = 122
				Decimal 122 is the character 'z'.

			int main()
			{
				char Z = 'Z';
				char x = 'x';
				char result;

				result = Z | x;
				printf("%c\n", result);
			}

			Output: z


		(^) Bit-wise XOR:

			Z ^ x

				Z in binary is: 01011010
				x in binary is: 01111000

				Returns a 1 in each bit position for which the corresponding bits
				of either but not both operands are 1s.

						01011010
						01111000
				      ------------
						00100010

				00100010 = 34
				Decimal 34 is the character '"'.

			int main()
			{
				char Z = 'Z';
				char x = 'x';
				char result;

				result = Z ^ x;
				printf("%c\n", result);
			}

			Output: "


		(~) Bit inversion:

			~Z

				Z in binary is: 01011010

				Invert all bits in an integer variable. All 1's become zero and all
				0's become ones.

						01011010
				      ------------
						10100101

				10100101 = 165
				Decimal 165 is the character 'Â¥'.

			int main()
			{
				char Z = 'Z';

				Z = ~Z;
				printf("%c\n", result);
			}

			Output: "


---------------------------------------------------------------------------------------------

Convert Character to Binary:

	Let's take the character 'Z'.
	It's Ascii code in decimal is 90.

	90 in binary is:

		128    64    32    16     8     4     2     1

		2^7   2^6   2^5   2^4   2^3   2^2   2^1   2^0
	-----------------------------------------------------
		 0     1     0     1      1     0     1     0

	'Z' is binary to 01011010


Convert Character to Binary in Code Explanation:

	There are 8 bits in a character.

	To convert Character to Binary you have to compare all bits shifted to the right
	to 1 using (&) AND.

	1 in binary is:
		00000001

	To compare ALL bits of the 'Z' to 1 you have to shift every single one of them.

	First Step:															RESULT = 0

			Z is		= 01011010
			Z >> 7 is	= 00000000

			Z >> 7 & 1	= 00000000
						  00000001
						------------
						  00000000   = 0

			Z >> 7 & 1 = 0;

	Second Step:														RESULT = 01

			Z is		= 01011010
			Z >> 6 is	= 00000001

			Z >> 6 & 1	= 00000001
				  		  00000001
						------------
						  00000001   = 1

			Z >> 6 & 1 = 1;


	Third Step:															RESULT = 010

			Z is		= 01011010
			Z >> 5 is	= 00000010

			Z >> 5 & 1	= 00000010
				  		  00000001
						------------
						  00000000   = 0

			Z >> 5 & 1 = 0;


	Fourth Step:															RESULT = 0101

			Z is		= 01011010
			Z >> 4 is	= 00000101

			Z >> 4 & 1	= 00000101
				  		  00000001
						------------
						  00000001   = 1

			Z >> 4 & 1 = 1;


	Fifth Step:															RESULT = 01011

			Z is		= 01011010
			Z >> 3 is	= 00001011

			Z >> 3 & 1	= 00001011
				  		  00000001
						------------
						  00000001   = 1

			Z >> 3 & 1 = 1;


	Sixth Step:															RESULT = 010110

		" Z >> 2 & 1 = ? "

			Z is		= 01011010
			Z >> 2 is	= 00010110

			Z >> 2 & 1	= 00010110
				  		  00000001
						------------
						  00000000   = 0

			Z >> 2 & 1 = 0;


	Seventh Step:														RESULT = 0101101

		" Z >> 1 & 1 = ? "

			Z is		= 01011010
			Z >> 1 is	= 00101101

			Z >> 1 & 1	= 00101101
				 		  00000001
						------------
						  00000001   = 1

			Z >> 1 & 1 = 1;


	Eighth Step:														RESULT = 01011010

		" Z >> 0 & 1 = ? "

			Z is		= 01011010
			Z >> 0 is	= 01011010

			Z >> 0 & 1	= 01011010
				 		  00000001
						------------
						  00000000   = 0

			Z >> 0 & 1 = 0;


	Final Step:

		Result is 01011010 which indeed is Z.


Convert Character to Binary in Code:

	int main()
	{
		char Z = 'Z';

		int bits = 7;
		while (bits >= 0)
		{
			char bit = (Z >> bits & 1) + 48;
			write(1, &bit, 1);
			bits--;
		}
		write(1, "\n", 1);
	}

	Output: 01011010

		The "+ 48" is to convert integer 0 to char '0' and integer 1 to char '1'.


Convert Binary to Character in Code:

	int main()
	{
		int binary_table[8] = {128, 64, 32, 16, 8, 4, 2, 1};
		int converted = 0;

		i = 0;
		while (i < 8)
		{
			if (binary[i] == '1')
				converted += binary_table[i];
			i++;
		}
		write(1, &converted, 1);
		write(1, "\n", 1);
	}

---------------------------------------------------------------------------------------------

</code>
