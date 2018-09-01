

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "input_parser",
    srcs = ["input_parser/input_parser.cpp"],
    hdrs = ["input_parser/input_parser.h"]
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "logger",
    srcs = ["logger/logger.cpp"],
    hdrs = ["logger/logger.h"]
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "op_gen",
    srcs = ["op_gen/op_gen.cpp"],
    hdrs = ["op_gen/op_gen.h"]
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "main_app",
    srcs = ["app/main_app.cpp"],
    copts = [],
    deps = [":input_parser", "logger", "op_gen"],
)