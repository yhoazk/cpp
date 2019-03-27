
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

void do_heartbeat(){

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

    sid = sedsid();

    if(sid < 0){
        syslog(LOG_ERR, "Unable to generate session ID for child process");

        exit(EXIT_FAILURE);
    }

    if((chdir("/")) < 0){
        syslog(LOG_ERR, "Unable to change working dir to '/'");
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    const int SLEEP_INTERVAL = 5;

    while(1){
        do_heartbeat();

        sleep(SLEEP_INTERVAL);
    }

    syslog(LOG_NOTICE, "Stopping daemon-named");
    closelog();

    exit(EXIT_SUCCESS);
}