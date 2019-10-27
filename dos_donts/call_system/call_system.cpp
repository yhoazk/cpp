#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <cerrno>
#include <fcntl.h>

namespace my
{
    // Why use popen when the string is not needed?
    bool pop(std::string cmd){
        FILE *process {0};
        char response[1024];
        bool call_status{false};
        process = popen(cmd.c_str(), "r");
        int fd_process = fileno(process);
        fcntl(fd_process, F_SETFL, O_NONBLOCK);
        if(process == 0){
            std::cerr << "popen: " << strerror(errno) ;
            return false;
        }
        while(fgets(response, sizeof(response-1), process) != NULL){
            std::cout << response << std::endl;
        }
        // on succes pclose returns the exit status of the command
        // on error returns -1
        // the return value of the children process is given on the 
        // bits [7:15] second byte
        // we need to poll for this process to end and not block this 
        // thread. The pclose should be non-blocking to allow the program
        // to continue
        int shell_status = pclose(process);
        if(-1 == shell_status){
            std::cerr << "pclose call failed: " << strerror(errno);
        } else {
            std::cerr << "Script finished with errno: " << strerror(errno) << '\n';
            std::cout << "shell stat: " << static_cast<int>((shell_status & 0xff00) >> 8) << '\n';
        } 
        return call_status;
    }
} // namespace 

int main(){
    /* simple systemcall */
   for(int k =5; k>0;--k){
       int exit_val = system("./my_script.sh &");
       std::cout << "Exit val: " << std::hex << exit_val << std::endl;
   }
    // this way it will block on every call and wait for finish
    // what is needed is to verify if the script is already running
    // and do exit of true
//    for(int k =5; k>0;--k)
        // my::pop("./my_script.sh &");
    return 0;
}