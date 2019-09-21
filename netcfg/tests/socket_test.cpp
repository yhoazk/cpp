#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::Return;
using ::testing::_;

class nl_sockMock : public netlink::nl_socket {
public:
    MOCK_METHOD(bool, allocate, ());
}

#include "backend/netlink_socket.h"

TEST(SocketShould, CreateFileDescriptor){
    nl_sockMock mock;
    EXPECT_CALL(mock, allocate);
    mock.allocate();
    // netlink::nl_socket<netlink::protocol::route> nlsocket;
}
