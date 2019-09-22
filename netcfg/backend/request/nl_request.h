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
    struct {
        struct nlmsghdr hdr;
        struct rtgenmsg gen;
    } rq;
    request(): rq{0} {}
    void create(rtnlmsg_class msg_class, rtnl_op op);
    void* data();

};
} /* namespace netlink */
#endif /* _NL_REQUEST_ */