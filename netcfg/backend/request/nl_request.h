#ifndef _NL_REQUEST_
#define _NL_REQUEST_

extern "C" {
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <sys/types.h>
#include <sys/socket.h>
const size_t sockaddr_nl_len = sizeof(struct sockaddr_nl);
}

namespace netlink {

constexpr size_t nlmsg_length(size_t msg_len){
    return NLMSG_LENGTH(msg_len);
}

bool nlmsg_ok(nlmsghdr* msg, size_t len){
    return NLMSG_OK(msg, len);
}

/* Get the length of a RTA struct with data size of rta */
constexpr size_t rta_len(size_t rta){
    return RTA_LENGTH(rta);
}

rtattr* rtm_rta( rtmsg* rmsg){
    return RTM_RTA(rmsg);
}

rtattr* rta_next(rtattr* rta, size_t len){
    return RTA_NEXT(rta, len);
}

bool rta_ok(rtattr* rta, size_t len){
    return RTA_OK(rta, len);
}

void* rta_data(rtattr* attr){
    return RTA_DATA(attr);
}

enum class rtnl_op : int {
    new_op = 0,
    del_op,
    get_op,
    set_op
};

/* Each of this messages have the operations:
- new
- del
- get
- (optionally ) set
*/
enum class rtnlmsg_class : int {
    link = RTM_NEWLINK,    /* network interface */
    addr = RTM_NEWADDR,    /* */
    route= RTM_NEWROUTE,   /* */
    neigh = RTM_NEWNEIGH,   /* */
    rule = RTM_NEWRULE,    /* */
    qdisc = RTM_NEWQDISC,   /* */
    tclass = RTM_NEWTCLASS,  /* */
    tfilter = RTM_NEWTFILTER /* */
};


class request{
public:
    struct nlmsghdr* hdr;
    // defines the type of message 
    // the location of the rtmsg follows the location 
    // of the nlmsghdr
    struct rtmsg* rt;
    // pointer to the start of the attribure block
    // this attribute block is part of the main buffer
    struct rtattr* req_attr;
    // pointer to the current attribute
    // used for multiattr messages
    struct rtattr* current_attr;
    // number of attributes contained in the request
    size_t attr_num;
    request(): hdr{0}, rt{0}, attr_num{0} {}
    void create(rtnlmsg_class msg_class, rtnl_op op);
    // Adds an attribute to the request
    // returns the pointer to the end of the attr block
    // to insert the next attr
 
    rtattr* add_attr(rtattr_type_t type, size_t data_len, void* data);
    // returns the pointer to the begining of the data msghdr...
    void* data();
};
} /* namespace netlink */
#endif /* _NL_REQUEST_ */