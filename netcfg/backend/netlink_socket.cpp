#include "netlink_socket.h"

namespace netlink {

    // template<>
    // bool nl_socket<protocol::route>::allocate(){
    bool nl_socket::allocate(){
       sfd = socket(AF_NETLINK, SOCK_RAW | SOCK_CLOEXEC, NETLINK_ROUTE);
       return (sfd != -1);
    }

    nl_socket::~nl_socket(){
        //close(sfd);
    };
    // template<>
    // bool nl_socket<protocol::route>::_bind(){
    bool nl_socket::_bind(){
        if(-1 == this->sfd) return false;

        struct sockaddr_nl snl;
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
    void nl_socket::show(){
        std::cout << "Socket Descriptor: " << this->sfd;
        std::cout << "\nThe socket is" << (binded? " " : " not ") << "binded\n";
    }
}