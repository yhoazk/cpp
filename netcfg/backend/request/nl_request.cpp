
#include "nl_request.h"

namespace netlink {

void request::create(rtnlmsg_class msg_class, rtnl_op op){
    rq.hdr.nlmsg_len = nlmsg_length(sizeof(struct rtgenmsg));
    rq.hdr.nlmsg_type = static_cast<int>(msg_class) + static_cast<int>(op);
    rq.hdr.nlmsg_flags = NLM_F_REQUEST;
    rq.hdr.nlmsg_seq = 1;
    rq.hdr.nlmsg_pid = 0; //tgt; /* Normally requests will be directed to kernel */
    rq.gen.rtgen_family = AF_INET;
}

void* request::data(){ return &rq; }

} // namespace netlink
