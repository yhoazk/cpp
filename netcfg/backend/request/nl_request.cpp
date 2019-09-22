
#include "nl_request.h"

extern "C" {
    #include <string.h>
}

namespace netlink {

void request::create(rtnlmsg_class msg_class, rtnl_op op){
    hdr->nlmsg_len = nlmsg_length(sizeof(struct rtgenmsg)) + rta_len(4); // for the IP address to be increased for every attr
    hdr->nlmsg_type = static_cast<int>(msg_class) + static_cast<int>(op);
    hdr->nlmsg_flags = NLM_F_REQUEST | NLM_F_DUMP | NLM_F_ATOMIC;
    hdr->nlmsg_seq = 1;
    hdr->nlmsg_pid = 0; //tgt; /* Normally requests will be directed to kernel */

    rt = reinterpret_cast<struct rtmsg*>(hdr+1);
    rt->rtm_family = AF_INET;
    rt->rtm_dst_len = 0; // if 0 is used we ask for all the entries
    rt->rtm_src_len = 0;

}

rtattr* request::add_attr(rtattr_type_t type, size_t data_len, void* data){
    // increase the nlmsghdr len to reflect the new attr
    hdr->nlmsg_len += rta_len(data_len);
    if(attr_num == 0) {
        req_attr = rtm_rta(rt); // assign the addres of the rtmsg to get the offset and add the attribute
        // assing the first attribute
        current_attr = req_attr;
    }
    attr_num++;
    current_attr->rta_type = type;
    current_attr->rta_len = rta_len(data_len);
    // copy the given data to the main buffer
    // TODO: create a rta class to avoid calling C fncs
    memcpy(rta_data(current_attr), data, data_len);
    // FIX: is the second parameter correct or it depens on the nlmsghdr
    return rta_next(current_attr, current_attr->rta_len);
}

void* request::data(){ return hdr; }

} // namespace netlink
