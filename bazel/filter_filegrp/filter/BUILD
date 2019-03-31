load("//:filter.bzl", "filtered_genrule")

"""
List of incompatible changes
https://docs.bazel.build/versions/master/skylark/backward-compatibility.html
"""

filtered_genrule(
    name = "mylib",
    cfg  = ["cfg/lib.json"],
    outs = ["gen_lib/adder.h", "gen_src/adder.cpp", "gen_cfg/adder.json"]
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "libmain",
    srcs = [],
    hdrs = [],
    deps = [":mylib"],)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "main",
    srcs = ["src/main.cpp"],
   # copts = [],
    deps = [":libmain"],
)