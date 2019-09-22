#ifndef _NLMSG_
#define _NLMSG_

extern "C" {
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <sys/types.h>
#include <sys/socket.h>
}

#include "backend/netlink_socket.h"
#include "backend/request/nl_request.h"



// this class represetns an interaction with netlink
// will create the connection and fill the data with the 
// given messages. It will not own the buffer which will
// be used to fill the request information and then
// will use the same buffer to write the response data
// this class is independen of the type of operation 
// to be sent to the netlink
class nlmsg {
public:
    struct msghdr interaction;
    struct iovec io;
    netlink::nl_socket conn;

    nlmsg() : interaction{0}, io{0}, conn() {
        interaction.msg_iov = &io;
        // set the number of elements in iov
        interaction.msg_iovlen = 1;
    }

    void open_connection();
    void set_iovnumber(size_t n);
    void set_iovec(void* data, size_t len);
    size_t call();
    size_t get(std::vector<std::uint8_t>&);
    void append_request(netlink::request& );
};

#endif /* _NLMSG_ */