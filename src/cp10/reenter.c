#include "apue.h"
#include <pwd.h>

static void
my_alarm(int signo)
{
	struct passwd	*rootptr;

	printf("in signal handler\n");
	if ((rootptr = getpwnam("root")) == NULL)
			err_sys("getpwnam(root) error");
	/* printf("start alarm to send signal SIGALRM\n"); */
	alarm(1);
}

int
main(void)
{
	struct passwd	*ptr;

	signal(SIGALRM, my_alarm);
	alarm(1);
	for ( ; ; ) {
		if ((ptr = getpwnam("chenky")) == NULL)
			err_sys("getpwnam error");
		if (strcmp(ptr->pw_name, "chenky") != 0)
			printf("return value corrupted!, pw_name = %s\n", ptr->pw_name);
		/* else
			printf("return value successed!, pw_name = %s\n", ptr->pw_name); */
	}
}
