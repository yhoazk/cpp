/**
 * - fork off the parent process & let it terminate if forking was successful
 *   because the parent has terminated, the child process now runs in the bkg
 * - setsid: Create a new session, The calling process becomes the leader of
 *   the new session and the process group leader of the new process group.
 *   The process is now detached from its controlling terminal (ctty)
 * - catch signals which will be sent with the kill tool
 * - fork again & let the parent process terminate to ensure that you get rid
 *   of the session leading process (only session leaders may get a TTY again)
 * - chdir: change the working directory of the daemon
 * - umask change the file mode mask according ti the needs of the daemon
 * - close all open file descriptors that may be inherited from the parent
 * 
 * To check if the process is now a daemon:
 * `ps -xj | grep daemon`
 * The expected output
 * +------+------+------+-----+-----+-------+------+-----+------+-----+
 * | PPID | PID  | PGID | SID | TTY | TPGID | STAT | UID | TIME | CMD |
 * +------+------+------+-----+-----+-------+------+-----+------+-----+
 * |    1 | 6465 | 6464 | 6464|  ?  |     -1|  S   | 100 | 0:00 | ./  |
 * +------+------+------+-----+-----+-------+------+-----+------+-----+
 * 
 * The process has no attached TTY
 * The parent PID is now 1 or init process
 * The PID != SID which means that the process is not the session leader
 * 
 * As PID != SID the process cant take control of a TTY again
 * 
 * Reading the syslog:
 *  - locate the syslog normally in `/var/log/syslog`
 *  - Do a `grep daemon /var/log/syslog`
 * */


#include <dirent.h>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <syslog.h>
#include <unistd.h>
#include <vector>
#include <signal.h>

void do_heartbeat(){
    syslog(LOG_INFO, "heart bit");
}

int main(void){
    pid_t pid, sid;

    pid = fork();
    if(pid > 0){
        exit(EXIT_SUCCESS);
    } else if(pid < 0){
        exit(EXIT_FAILURE);
    }

    umask(0);

    openlog("daemon-named", LOG_NOWAIT | LOG_PID, LOG_USER);
    syslog(LOG_NOTICE, "Started my daemon");
    // setsid creates a session and sets the process group ID
    sid = setsid();

    if(sid < 0){
        syslog(LOG_ERR, "Unable to generate session ID for child process");

        exit(EXIT_FAILURE);
    }
    
    /* catch, ingore and handle signals */
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);
    signal(SIGKILL, SIG_IGN);
    signal(SIGTERM, SIG_IGN);

    if((chdir("/")) < 0){
        syslog(LOG_ERR, "Unable to change working dir to '/'");
        exit(EXIT_FAILURE);
    }

    #if 0
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    #endif
    /* close all open file descriptors */
    int x;
    for(x = sysconf(_SC_OPEN_MAX); x>=0; --x){
        close(x);
    }

    const int SLEEP_INTERVAL = 15;

    while(1){
        do_heartbeat();

        sleep(SLEEP_INTERVAL);
    }

    syslog(LOG_NOTICE, "Stopping daemon-named");
    closelog();

    exit(EXIT_SUCCESS);
}