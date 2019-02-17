# The actual rule which does the filtering.
def _do_filter_impl(ctx):
  return struct(
    files = depset([f for f in ctx.files.srcs if f.path.endswith(ctx.attr.suffix)]),
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
def filtered_genrule(name, cfg, outs, **kwargs):
  """Generate the files according to configuration
  Returns a file group for each extension type in the generated
  output.
  """
'''   _do_filter(
    name = "%s_hdrs" % name,
    visibility = ["//visibility:private"],
    srcs = hdrs,
    suffix = ".hpp",
  )
    srcs = [ ":%s_srcs" % name ],
  _do_filter(
    name = "%s_srcs" % name,
    visibility = ["//visibility:private"],
    srcs = srcs,
    suffix = ".cpp",
  ) '''
  GEN_BIN="gen/code_generator.py"
  
  native.genrule(
    name = name,
    srcs = cfg,
    outs = outs,
    cmd = "python {} $(@)".format(GEN_BIN)
    **kwargs
  )