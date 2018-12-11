

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
  name = "stdy_timer",
  srcs = ["stdy_timer.cpp"],
  #deps = ["@boost//:boost"],
  copts = ["-std=c++14", "-DBOOST_SYSTEM_NO_DEPRECATED"],
  # not working ->defines = ["BOOST_SYSTEM_NO_DEPRECATED"],
  linkopts = ["-lboost_system"] # This isn not always needed, as it links the complente system lib
)