cc_library(
    name = "foo1",
    srcs = ["libFoo1.cpp"],
    hdrs = ["foo.h"],
)

cc_library(
    name = "foo2",
    srcs = ["libFoo2.cpp"],
    hdrs = ["foo.h"],
)

cc_binary(
    name = "link_1_2",
    srcs = ["link_order.cpp", "foo.h"],
    deps = [
        ":foo1",
        ":foo2",
    ]
)

cc_binary(
    name = "link_2_1",
    srcs = ["link_order.cpp", "foo.h"],
    deps = [
        ":foo2",
        ":foo1",
    ]
)