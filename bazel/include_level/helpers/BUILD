

filegroup(
  name = "fg_helper_hdrs",
  srcs = glob(["some_folder/**/*.h"]),
  visibility = ["//visibility:public"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
  name = "helper_hdrs",
  srcs = glob(["some_folder/**/*.h"]),#[":fg_helper_hdrs"],
  # hdrs are the public interface and can be included in hdrs and srcs
  hdrs = [":fg_helper_hdrs"],
  #deps = [":fg_helper_hdrs"],
  linkstatic = 1,
  strip_include_prefix = "some_folder/some_other_folder/include",
  visibility = ["//visibility:public"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
  name = "helper_iface_hdrs",
  hdrs = ["src/helper.h"],
  #srcs = ["src/helper.h"], this is not needed
  strip_include_prefix = "src",
  visibility = ["//visibility:public"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
  name = "helper",
  srcs = ["src/helper.cpp"],
  #hdrs = [":helper_hdrs", ":helper_iface_hdrs"],
  deps = [":helper_hdrs", ":helper_iface_hdrs"],
  visibility = ["//visibility:public"],
)