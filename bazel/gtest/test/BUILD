cc_test(
    name = "tests",
    srcs = glob(["**/*.cc"]),
    deps = [
        "//src/lib:GreetingLib",
        "@googletest//:gtest_main", # Include this to avoid the empty main for RUN_ALL_TESTS
    ],
)
