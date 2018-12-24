# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "find_path_bfs",
    srcs = ["find_path_bfs.cpp"],
    hdrs = ["find_path_bfs.h"]
    #deps = ["header filesfin"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "find_path",
    srcs = ["find_path.cpp"],
    copts = ["--std=c++14"],
    deps = [":find_path_bfs", "@gtest//:gtest_main"],
)
