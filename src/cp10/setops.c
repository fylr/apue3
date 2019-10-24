#include	<signal.h>
#include	<errno.h>
#include	<stdio.h>

/*
 * <signal.h> usually defines NSIG to include signal number 0.
 */
#define	SIGBAD(signo)	((signo) <= 0 || (signo) >= NSIG)

int
sigaddset(sigset_t *set, int signo)
{
	if (SIGBAD(signo)) {
		errno = EINVAL;
		return(-1);
	}
	*(unsigned long *)set |= 1UL << (signo - 1);		/* turn bit on */
	return(0);
}

int
sigdelset(sigset_t *set, int signo)
{
	if (SIGBAD(signo)) {
		errno = EINVAL;
		return(-1);
	}
	*(unsigned long *)set &= ~(1UL << (signo - 1));	/* turn bit off */
	return(0);
}

int
sigismember(const sigset_t *set, int signo)
{
	if (SIGBAD(signo)) {
		errno = EINVAL;
		return(-1);
	}
	return((*(unsigned long *)set & (1UL << (signo - 1))) != 0);
}

int
main(void)
{
	sigset_t sigset;
	sigemptyset(&sigset);

	if(sigismember(&sigset, SIGUSR1))
		printf("yes, signal SIGUSR1 is in sigset\n");
	else
		printf("no,signal SIGUSR1 is not in sigset\n");

	sigaddset(&sigset, SIGUSR1);

	if(sigismember(&sigset, SIGUSR1))
		printf("yes, signal SIGUSR1 is in sigset\n");
	else
		printf("no,signal SIGUSR1 is not in sigset\n");
	
	sigdelset(&sigset, SIGUSR1);

	if(sigismember(&sigset, SIGUSR1))
		printf("yes, signal SIGUSR1 is in sigset\n");
	else
		printf("no,signal SIGUSR1 is not in sigset\n");

	return 0;
}
