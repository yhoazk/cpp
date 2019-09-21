cc_test(
    name = "netlink_socket_tests",
    srcs = glob(["**/*.cpp"]),
    deps = [
        "@googletest//:gtest_main", # Include this to avoid the empty main for RUN_ALL_TESTS
        "//backend:netlink_socket"
    ],
)
