load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
  name = "anon_union_leak",
  srcs = ["anon_union.cpp"],
  # copts = [],
  # deps = ["libraries to be linked"],
  defines = ["LEAK"]
)


cc_binary(
  name = "anon_union_no_leak",
  srcs = ["anon_union.cpp"],
  # copts = [],
  # deps = ["libraries to be linked"],
)

pkg_tar(
    name = "leaky",
    package_dir = "/tmp",
    srcs = [":anon_union_leak"],
    mode = "0755",
)


pkg_tar(
    name = "non_leaky",
    package_dir = "/tmp",
    srcs = [":anon_union_no_leak"],
    mode = "0755",
)

sh_test(
  name = "test_leaky",
  srcs = ["test_leaks.sh"],
  args = ["anon_union_leak"],
  data = [":anon_union_leak"]
)

sh_test(
  name = "test_non_leaky",
  srcs = ["test_leaks.sh"],
  args = ["anon_union_no_leak"],
  data = [":anon_union_no_leak"]
)