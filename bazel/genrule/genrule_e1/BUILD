

genrule(
        name = "foo",
        srcs = [],
        outs = ["foo.h"],
        cmd = "./$(location create_foo.sh) > \"$@\"",
        tools = ["create_foo.sh"],
)
