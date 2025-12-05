#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);

sighandler_t mysignal(int signo, sighandler_t handler) {
    struct sigaction act, oldact;
    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if (sigaction(signo, &act, &oldact) < 0)
        return SIG_ERR;
    return oldact.sa_handler;
}

void alarmHandler(int signo) {
    printf("Wake up\n");
    exit(0);
}

int main() {
    mysignal(SIGALRM, alarmHandler);
    alarm(5);
    int i = 0;
    while (1) {
        sleep(1);
        i++;
        printf("%d second\n", i);
    }
    return 0;
}
