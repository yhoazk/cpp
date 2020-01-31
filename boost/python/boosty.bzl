
cc_library(
    name = "boosty",
    srcs = glob(["src/**/*.cpp",]),
    hdrs = glob(["include/**/*.hpp"]),
    strip_include_prefix = "include",
    deps = ["@local_python//:local_python"],
    visibility = ["//visibility:public"]
)
