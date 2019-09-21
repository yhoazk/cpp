#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "backend/netlink_socket.h"

using ::testing::Return;
using ::testing::_;
using namespace netlink;

class nl_sockMock : public Isocket {
public:
    MOCK_METHOD(bool, allocate, (override));
}

#include "backend/netlink_socket.h"

TEST(SocketShould, CreateFileDescriptor){
    nl_sockMock mock;
    EXPECT_CALL(mock, allocate);
    mock.allocate();
    // netlink::nl_socket<netlink::protocol::route> nlsocket;
}
