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