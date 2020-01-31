# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "python_cpp",
    srcs = ["hello_python.cpp"],
    deps = ["@boost_python//:boosty"],
)

# bazel build @boost_python//:boosty --sandbox_debug