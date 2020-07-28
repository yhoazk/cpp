

cc_library(
    name = "memchecker",
    srcs = ["memcheck/memchecker.cpp"],
    hdrs = ["memcheck/memchecker.h"],
    strip_include_prefix = "memcheck",
    alwayslink = True
)

cc_binary(
    name = "memcheck",
    srcs = ["main.cpp"],
    deps = [":memchecker"]
)