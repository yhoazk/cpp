
#include "backend/nlmsg.h"
/*
send the message to the socket abstraction
depending on the type of the message requested
the socket will be created with the necessary 
protocol
*/

// return an iterator of all the NLMSGS received

void nlmsg::open_connection(){
    conn.allocate();
    conn._bind();
    interaction.msg_name = conn.get_name();
    interaction.msg_namelen = sockaddr_nl_len;
}
void nlmsg::set_iovnumber(size_t n){
        interaction.msg_iovlen = n;
}

void nlmsg::set_iovec(void* data, size_t len){
    io.iov_base = data;
    io.iov_len = len;
}

// send the message
size_t nlmsg::call(){
    conn.request(&interaction);
}

size_t nlmsg::get(std::vector<std::uint8_t>& rx_buff){
    return conn.receive(rx_buff);
}

void nlmsg::append_request(netlink::request& req) {
    nlmsghdr* ptype;
    ptype = reinterpret_cast<struct nlmsghdr*>(req.data());
    set_iovec(ptype, ptype->nlmsg_len);
}