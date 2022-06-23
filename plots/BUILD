cc_binary(
    name = "plot",
    srcs = ["plot.cpp", ],
    deps = [":fir"]
)

cc_library(
    name  = "fir",
    srcs = ["fir.cpp"],
    hdrs = ["fir.h"]
)

genrule(
    name = "audio",
    cmd = "$(location  arecord -d 5 -f FLOAT_LE  -t raw test.raw )",
    outs = ["test.raw"]
)

genrule(
    name = "csv",
    tools = [":plot"],
    srcs = [":audio"],
    #cmd = "$(location :plot > data.csv)",
    cmd = "$(location file  test.raw)",
    outs = ["data.csv"]
)
