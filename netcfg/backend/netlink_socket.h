#ifndef _NETLINK_SOCKET_
#define _NETLINK_SOCKET_


#include "request/nl_request.h"
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

namespace netlink {

    using socket_t = int;
    using nl_req_t = struct {struct nlmsghdr hdr; struct rtgenmsg gen; };
    const size_t nlmsg_len = sizeof(struct  nlmsghdr);
    const size_t rtgenmsg_len = sizeof(struct  rtgenmsg);
    const size_t msghdr_len = sizeof(struct msghdr);

    /* This message will contain the request */
    class rtnl_msg{
    public:
        struct msghdr hdr;
        struct iovec io;
        /* For a message is needed the pair socket and msg */
        rtnl_msg(): hdr{0}, io{0} {
            hdr.msg_iov = &io;
            /* For netlink messages the namelen is always the same */
            hdr.msg_namelen = sockaddr_nl_len;
            hdr.msg_iovlen = 1; 
        }
        rtnl_msg(sockaddr_nl* sock, request* rq): rtnl_msg() {
            set_sockaddr(sock);
            set_msgcontent(rq);
        }
        void set_iovlen(size_t len = 1){
            /* The regular case is to send only one request */
            hdr.msg_iovlen = len;
        }

        void set_sockaddr( sockaddr_nl* sck){
            hdr.msg_name = sck;
        }
        
        void set_msgcontent( request* req){
            io.iov_base = req;
            io.iov_len = req->rq.hdr.nlmsg_len;
        }

        void set_msgcontent(std::vector<std::uint8_t>& data_buf){
            io.iov_base = data_buf.data();
            io.iov_len  = data_buf.capacity();
        }
        /* Check if the life of hdr and io is safe or memcpy them */
        struct msghdr* data(){
            return &hdr;
        }
    };

    enum class socket_class {
        socket_route,
        socket_unused
    };
    
    enum class protocol {
        route = NETLINK_ROUTE,
    };

    class Isocket{
    public:
        virtual ~Isocket();
        virtual bool connect();
        virtual bool allocate();
        virtual bool _bind();
        // virtual bool request();
        // virtual bool receive();
    };

    //template<protocol P, socket_class T = socket_class::socket_route>
    class nl_socket {
    private:
        socket_t sfd{-1};
        bool binded{false};
        struct sockaddr_nl snl;
    public:
        nl_socket(/* args */): sfd{-1}, binded{false} {};
        ~nl_socket();
        bool connect();
        bool allocate();
        bool _bind();
        void show();
        struct sockaddr_nl* get_name() {return &snl; }
        // send the netlink request
        // there is only one type of data for the request?
            // what types of requests should we support?
        size_t request(rtnl_msg&);
        ssize_t receive(std::vector<std::uint8_t>&);
    };

} /* namespace netlink */
#endif /* _NETLINK_SOCKET_ */
