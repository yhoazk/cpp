# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
  name = "sub",
  hdrs = ["sub.cpp"],
)

cc_binary(
  name = "prog11",
  srcs = ["prog11.cpp"],
  copts = [],
  deps = [":sub"],
)