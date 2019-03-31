load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")
load("@bazel_tools//tools/build_defs/pkg:rpm.bzl", "pkg_rpm")

pkg_tar(
  name = "hello_bin",
  strip_prefix = "src",
  package_dir = "/usr/bin",
  srcs = ["//src:bazel_hello"],
  mode = "0755",
)


pkg_deb(
  name = "bazel_hi",
  architecture = "amd64",
  built_using = "bazfoo 3.1415",
  data = ":hello_bin",
  depends = [
    "unzip",
    "python",
  ],
  package = "bazel_hallo",
  description = "debian/description",
  version = "0.001",
  maintainer = "Mrs Thompson"
)

pkg_rpm(
  spec_file = "",
  architecture = "amd64",
  version = "0.001",
  data = ":hello_bin",
  debug = True,
)

