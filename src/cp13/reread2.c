#include "apue.h"
#include <errno.h>
#include <pthread.h>
#include <syslog.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/resource.h>

void
daemonize(const char *cmd)
{
        int                     i, fd0, fd1, fd2;
        pid_t                   pid;
        struct rlimit           rl;
        struct sigaction        sa;

        /*
 *  *          * Clear file creation mask.
 *   *                   */
        umask(0);

        /*
 *  *          * Get maximum number of file descriptors.
 *   *                   */
        if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
                err_quit("%s: can't get file limit", cmd);

        /*
 *  *          * Become a session leader to lose controlling TTY.
 *   *                   */
        if ((pid = fork()) < 0)
                err_quit("%s: can't fork", cmd);
        else if (pid != 0) /* parent */
                exit(0);
        setsid();

        /*
 *  *          * Ensure future opens won't allocate controlling TTYs.
 *   *                   */
        sa.sa_handler = SIG_IGN;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;
        if (sigaction(SIGHUP, &sa, NULL) < 0)
                err_quit("%s: can't ignore SIGHUP", cmd);
	if ((pid = fork()) < 0)
                err_quit("%s: can't fork", cmd);
        else if (pid != 0) /* parent */
                exit(0);

        /*
 *  *          * Change the current working directory to the root so
 *   *                   * we won't prevent file systems from being unmounted.
 *    *                            */
        if (chdir("/") < 0)
                err_quit("%s: can't change directory to /", cmd);

        /*
 *  *          * Close all open file descriptors.
 *   *                   */
        if (rl.rlim_max == RLIM_INFINITY)
                rl.rlim_max = 1024;
        for (i = 0; i < rl.rlim_max; i++)
                close(i);

        /*
 *  *          * Attach file descriptors 0, 1, and 2 to /dev/null.
 *   *                   */
        fd0 = open("/dev/null", O_RDWR);
        fd1 = dup(0);
        fd2 = dup(0);

        /*
 *  *          * Initialize the log file.
 *   *                   */
        openlog(cmd, LOG_CONS, LOG_DAEMON);
        if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
                syslog(LOG_ERR, "unexpected file descriptors %d %d %d",
                  fd0, fd1, fd2);
                exit(1);
        }
}

#define LOCKFILE "/var/run/daemon.pid"
#define LOCKMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
extern int lockfile(int);
// extern int already_running(void);

int
already_running(void)
{
        int             fd;
        char    buf[16];

        fd = open(LOCKFILE, O_RDWR|O_CREAT, LOCKMODE);
        if (fd < 0) {
                syslog(LOG_ERR, "can't open %s: %s", LOCKFILE, strerror(errno));
                exit(1);
        }
        if (lockfile(fd) < 0) {
                if (errno == EACCES || errno == EAGAIN) {
                        close(fd);
                        return(1);
                }
                syslog(LOG_ERR, "can't lock %s: %s", LOCKFILE, strerror(errno));
                exit(1);
        }
        ftruncate(fd, 0);
        sprintf(buf, "%ld\n", (long)getpid());
        write(fd, buf, strlen(buf)+1);
        return(0);
}

void
reread(void)
{
	/* ... */
}

void
sigterm(int signo)
{
	syslog(LOG_INFO, "got SIGTERM; exiting");
	exit(0);
}

void
sighup(int signo)
{
	syslog(LOG_INFO, "Re-reading configuration file");
	reread();
}

int
main(int argc, char *argv[])
{
	char				*cmd;
	struct sigaction	sa;

	if ((cmd = strrchr(argv[0], '/')) == NULL)
		cmd = argv[0];
	else
		cmd++;

	/*
	 * Become a daemon.
	 */
	daemonize(cmd);

	/*
	 * Make sure only one copy of the daemon is running.
	 */
	if (already_running()) {
		syslog(LOG_ERR, "daemon already running");
		exit(1);
	}

	/*
	 * Handle signals of interest.
	 */
	sa.sa_handler = sigterm;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGHUP);
	sa.sa_flags = 0;
	if (sigaction(SIGTERM, &sa, NULL) < 0) {
		syslog(LOG_ERR, "can't catch SIGTERM: %s", strerror(errno));
		exit(1);
	}
	sa.sa_handler = sighup;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGTERM);
	sa.sa_flags = 0;
	if (sigaction(SIGHUP, &sa, NULL) < 0) {
		syslog(LOG_ERR, "can't catch SIGHUP: %s", strerror(errno));
		exit(1);
	}

	/*
	 * Proceed with the rest of the daemon.
	 */
	/* ... */
	exit(0);
}
