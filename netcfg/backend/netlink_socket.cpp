

#include "netlink_socket.h"

namespace netlink {

    template<>
    bool nl_socket::allocate<protocol::route>(){
       sfd = socket(AF_NETLINK, SOCK_RAW | SOCK_CLOEXEC, NETLINK_ROUTE);
    }

    bool nl_socket::bind(){
        if(-1 == sfd) return false;

        struct sockaddr_nl snl;
        std::memset(&snl, 0, sizeof(stuct sockaddr_nl));
        snl.nl_family = AF_NETLINK;
        snl.nl_pid = 0; /* Message destination is kernel */
        binded = (0 == bind(sfd, (struct sockaddr*)&snl, sizeof(snl)));
        if(!binded){
            std::perror("nl_socket::bind failed");
        }
        return binded;
    }
}