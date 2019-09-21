
extern "C" {
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <linux/netlink.h>
}

#include <cerrno>

namespace netlink {

    using socket_t = int;
    enum class socket_class {
        socket_route,
        socket_unused
    };
    
    enum class protocol {
        route = NETLINK_ROUTE,
    };

    template<protocol P, socket_class T = socket_class::socket_route>
    class nl_socket {
    private:
        socket_t sfd{-1};
        bool binded{false};
    public:
        nl_socket(/* args */): sfd{-1}, binded{false};
        virtual ~_socket();
        bool connect();
        bool allocate<P>();
        bool bind();
        // send the netlink request
        // there is only one type of data for the request?
            // what types of requests should we support?
        bool request();
        bool receive();
    };

} /* namespace netlink */