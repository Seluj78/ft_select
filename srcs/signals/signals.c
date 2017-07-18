# include "signals/signals.h"

void			set_signals(void (*restart_function)(int))
{
	signal(SIGWINCH, refresh_screen);
	signal(SIGCONT, restart_function);
	signal(SIGTSTP, abort_no_exit);
	signal(SIGINT, abort_exit);
	signal(SIGINT, abort_exit);
	signal(SIGHUP, abort_exit);
	signal(SIGTERM, abort_exit);
	signal(SIGSEGV, abort_exit);
	signal(SIGQUIT, abort_exit);
	signal(SIGFPE, abort_exit);
	signal(SIGALRM, abort_exit);
	signal(SIGKILL, abort_exit);
	signal(SIGABRT, abort_exit);
	signal(SIGUSR1, abort_exit);
	signal(SIGUSR2, abort_exit);
}
