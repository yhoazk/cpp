# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "array_view",
    srcs = ["array_view.cpp"],
    copts = ["-fsanitize=address,undefined", "-lasan", "-lubsan"],
)