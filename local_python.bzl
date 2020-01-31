# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "local_python",
    srcs = glob(["*.h"]),
    visibility = ["//visibility:public"],
    strip_include_prefix = "/usr/include/python3.7m"
)