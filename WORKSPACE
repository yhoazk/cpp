load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

git_repository(
    name = "googletest",
    # build_file = "@//:gmock.BUILD",
    # build_file = "@google//BUILD.bazel",
    remote = "https://github.com/google/googletest",
    tag = "release-1.8.1",
)

## git_repository vs new_git_repository ?
new_git_repository(
    name = "picojson",
    #remote = "git@github.com:kazuho/picojson.git",
    remote = "https://github.com/kazuho/picojson.git",
    tag = "v1.3.0",
    ## NOTE: the file is given with : not /
    build_file = "@//serialization/in_disk_file:picojson.bzl",
)

new_git_repository(
    name = "boost_python",	# Reference as @rule unique name//:target-lib
    remote = "https://github.com/boostorg/python.git",
    #tag = "boost-1.72.0",
    commit = "102acf1d34ff91e67fe9aae401edc6edd68be89e",
    shallow_since = "1553866906 -0400",
    build_file = "@//boost/python:boosty.bzl",
)

new_local_repository(
    name = "local_python",
    path = "/usr/include/python3.7m",
    build_file = "local_python.bzl",
)
