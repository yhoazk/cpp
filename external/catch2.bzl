cc_library(
    name = "catch2",
    srcs = glob(["single_include/**"]),
    strip_include_prefix = "single_include",
    visibility = ["//visibility:public"]
)

