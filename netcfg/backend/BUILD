package(default_visibility = ["//visibility:public"])
# cc_library(
#     name = "netlink_backend",
#     srcs = ["*.cpp"],
#     hdrs = ["*.h" ],
# )


# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "nlmsg",
    srcs = ["nlmsg.cpp"],
    hdrs = ["nlmsg.h"],
    deps = [":netlink_socket"],
)

cc_library(
    name = "netlink_socket",
    srcs = ["netlink_socket.cpp"],
    hdrs = ["netlink_socket.h" ],
    deps = ["//backend/request:nl_request"]
)