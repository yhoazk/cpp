# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "calc",
    srcs = glob(["**/*.cpp"]),
    hdrs = [":lib_hdrs"],
    visibility = ["//visibility:public"],
    includes = ["."]
    # strip_include_prefix = "src/lib/"
)


filegroup(
    name = "lib_hdrs",
    srcs = [
        "calc.h",
        "calc.cpp"
    ],
    visibility = ["//visibility:public"],
)