cc_test(
    name = "tests",
    srcs = glob(["**/*.cpp"]),
    deps = [
        "//src/lib:GreetingLib",
        "@googletest//:gtest_main", # Include this to avoid the empty main for RUN_ALL_TESTS
    ],
)
