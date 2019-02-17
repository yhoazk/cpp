load("//:filter.bzl", "filtered_genrule")

"""
List of incompatible changes
https://docs.bazel.build/versions/master/skylark/backward-compatibility.html
"""

filtered_genrule(
    name = "mylib",
    src  = ["cfg/lib.json"]
    outs = ["gen_lib/adder.h, gen_src/adder.cpp, gen_cfg/adder.json"]
)