#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
	pid_t	pid;

	if (system("echo '#!' `pwd`/echoall foo > testinterp; chmod a+x testinterp") < 0)
		err_sys("system() error");

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {			/* child */
		if (execl("./testinterp",
				  "testinterp", "myarg1", "MY ARG2", (char *)0) < 0)
			err_sys("execl error");
	}
	if (waitpid(pid, NULL, 0) < 0)	/* parent */
		err_sys("waitpid error");

	if (system("rm -f testinterp") < 0)
		err_sys("system() error");
	exit(0);
}
