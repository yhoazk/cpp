#include <bits/stdc++.h>
#include <syslog.h>
// what happens when the date is changed during the wait?
// https://stackoverflow.com/q/51483659
void for_5s(void){
    syslog(LOG_ERR, "Starting help thead");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    syslog(LOG_ERR, "End help thead");
}

int main(){
    // start syslog
    openlog("WAKE_UP",LOG_PID|LOG_CONS, LOG_USER);
    std::thread helper(for_5s);
    if(helper.joinable()){
        helper.detach();
    }
    while (true){
        syslog(LOG_ERR, "beep..");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    closelog();
    return 0;
}
