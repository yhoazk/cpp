

genrule(
        name = "foo",
        srcs = [],
        outs = ["foo.h"],
        # if we change the creation of hte foo.h file inside of the script, the rule will fail.
        #cmd = "./$(location create_foo.sh)",
        cmd = "./$(location create_foo.sh) > \"$@\"",
        tools = ["create_foo.sh"],
)

cc_binary(
        name = "main",
        srcs = ["main.cpp", "foo.h"]
        )
