#include "netlink_socket.h"

namespace netlink {

    bool nl_socket::allocate(){
       sfd = socket(AF_NETLINK, SOCK_RAW | SOCK_CLOEXEC, NETLINK_ROUTE);
       return (sfd != -1);
    }

    nl_socket::~nl_socket(){
        //close(sfd);
    };

    bool nl_socket::_bind(){
        if(-1 == this->sfd) return false;

        std::memset(&snl, 0, sizeof(struct sockaddr_nl));
        snl.nl_family = AF_NETLINK;
        snl.nl_pid = 0; /* Message destination is kernel */
        binded = (0 == bind(this->sfd, (struct sockaddr*)&snl, sizeof(snl)));
        if(!binded){
            std::perror("nl_socket::bind failed");
        }
        return binded;
    }

    bool nl_socket::connect(){
        return true;
    }
    
    size_t nl_socket::request(rtnl_msg& msg){
        ssize_t sent{0};
        sent = sendmsg(sfd, (struct msghdr*) msg.data(), 0);
        if(-1 == sent){
            std::perror("sendmsg:");
        }
        return sent;
    }
    // 
    ssize_t receive(){
        // the response is also a route link msg
        rtnl_msg resp;
        return 0;
    }
    void nl_socket::show(){
        std::cout << "Socket Descriptor: " << this->sfd;
        std::cout << "\nThe socket is" << (binded? " " : " not ") << "binded\n";
    }
}