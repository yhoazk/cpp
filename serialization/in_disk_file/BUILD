# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "in_disk",
    srcs = ["in_disk.cpp"],
    copts = ["-Wunknown-pragmas"],
    deps = ["@picojson//:picojson"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
# cc_library(
#     name = "picojson",
#     srcs = ["@picojson://picojson.h"],
#     hdrs = ["@picojson://picojson.h"],
# )

