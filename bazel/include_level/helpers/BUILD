

filegroup(
  name = "fg_helper_hdrs",
  srcs = glob(["some_folder/**/*.h"]),
  visibility = ["//visibility:public"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
  name = "helper_hdrs",
  srcs = glob(["some_folder/**/*.h"]),#[":fg_helper_hdrs"],
  #hdrs = ["header files"],
  #deps = [":fg_helper_hdrs"],
  linkstatic = 1,
  strip_include_prefix = "some_folder/some_other_folder/include",
  visibility = ["//visibility:public"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
  name = "helper",
  srcs = ["src/helper.cpp"],
  #hdrs = [":helper_hdrs"],
  deps = [":helper_hdrs"],
  visibility = ["//visibility:public"],
)