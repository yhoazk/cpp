

filegroup(
  name = "fg_helper_hdrs",
  srcs = glob(["some_folder/**/*.h"]),
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
  name = "helper_hdrs",
  srcs = [":fg_helper_hdrs"],
  #hdrs = ["header files"],
  #deps = [":fg_helper_hdrs"],
  linkstatic = 1,
  strip_include_prefix = "some_folder/some_other_folder/include"
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
  name = "helper",
  srcs = ["src/helper.cpp"],
  #hdrs = ["header files"],
  deps = [":helper_hdrs"],
)