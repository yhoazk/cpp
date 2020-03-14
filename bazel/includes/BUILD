# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "test_lib",
    hdrs = ["inc/config.h"],
    includes =["inc"]
)


# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "main",
    srcs = ["src/main.cpp"],
    deps = [":test_lib"]
)