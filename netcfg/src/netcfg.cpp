/*
    \brief some header information to be filled
*/
#include "netcfg.hpp"


bool get_ip(std::string iface_name){
    struct ifreq ifr;
    struct sockadd_in sock_in;
    int name_len = IFNAMSIZ;
    // zero the structs
    memset(&ifr, 0, sizeof(struct ifreq));
    memset(&sock_in, 0, sizeof(struct sockadd_in));

    // create the socket to communicate with the interface
    int  socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(socket_fd == -1){
        perror("Creting socket");
    } 
    // set the name of the interface we want to get the ip
    name_len = (name_len > iface_name.length())? iface_name.length() : name_len; 
    strncpy(ifr.iface_name, iface_name, name_len);

    if(ioctl(socket_fd, SIOCGIFADDR, &iface) < 0){
        perror("ioclt get ip");
    }

    sock_in = (struct sockaddr_in*)&ifr.ifr_addr;
    printf("%s\n", inet_ntoa(sock_in->sin_addr));
    return true;
}

int main(int argc, char*[] argv){
    return (0);
}