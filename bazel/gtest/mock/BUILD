# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "calc",
    srcs = glob(["src/lib/*.cpp"]),
    hdrs = [":lib_hdrs"],
    visibility = ["//visibility:public"],
    includes = ["lib"],
    strip_include_prefix = "src/lib/"
)


filegroup(
    name = "lib_hdrs",
    srcs = [
        "src/lib/calc.h",
        "src/lib/calc.cpp"
    ],
    visibility = ["//visibility:public"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "main",
    srcs = ["src/main/main.cpp",],
    deps = [":calc", ]
)

cc_test(
    name = "tests",
    # srcs = glob(["*.cpp"]),
    srcs = ["src/test/test.cpp", "src/test/mock_calc.h", ],
    # includes =["src/lib", "src/test", "."],
    includes =["src/test"],
    deps = [
        ":calc",
        "@googletest//:gtest_main", # Include this to avoid the empty main for RUN_ALL_TESTS
    ],
    
)
