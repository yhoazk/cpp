# The actual rule which does the filtering.
def _do_filter_impl(ctx):
  return struct(
    files = set([f for f in ctx.files.srcs if f.path.endswith(ctx.attr.suffix)]),
  )
_do_filter = rule(
  implementation = _do_filter_impl,
  attrs = {
    "srcs": attr.label_list(
      mandatory = True,
      allow_files = True,
    ),
    "suffix": attr.string(
      mandatory = True,
    ),
  },
)

# A convenient macro to wrap the custom rule and cc_library.
def filtered_cc_library(name, srcs, hdrs, **kwargs):
  _do_filter(
    name = "%s_hdrs" % name,
    visibility = ["//visibility:private"],
    srcs = hdrs,
    suffix = ".hpp",
  )
  _do_filter(
    name = "%s_srcs" % name,
    visibility = ["//visibility:private"],
    srcs = srcs,
    suffix = ".cpp",
  )
  native.cc_library(
    name = name,
    srcs = [ ":%s_srcs" % name ],
    hdrs = [ ":%s_hdrs" % name ],
    **kwargs
  )