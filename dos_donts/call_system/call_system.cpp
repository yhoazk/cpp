#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <cerrno>

namespace my
{
    bool pop(std::string cmd){
        FILE *process {0};
        char response[1024];
        bool call_status{false};
        process = popen(cmd.c_str(), "r");
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
//    for(int k =5; k>0;--k)
//        system("./my_script.sh");
    my::pop("./my_script.sh");
    return 0;
}