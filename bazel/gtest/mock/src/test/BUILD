cc_test(
    name = "tests",
    # srcs = glob(["*.cpp"]),
    srcs = ["test.cpp", "mock_calc.h", ],
    # includes =["src/lib", "src/test", "."],
    includes =["."],
    deps = [
        "//src/lib:calc",
        "@googletest//:gtest_main", # Include this to avoid the empty main for RUN_ALL_TESTS
    ],
    
)
