

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "logger_generator",
    srcs = ["src/log_generator.cpp"],
    #copts = ["-pthread"],
    linkopts = ["-pthread"],
    #deps = ["thread"],
)

py_test(
    name = "test_logger",
    srcs = ["test/test_logger.py"],
    data = [
        ":logger_generator" # This creates the depencency to the binary defined up
    ],
)