
load("@bazel_skylib//:lib.bzl", "paths")

def _py_gen_imp(ctx):
  args = ctx.actions.args()
  print(args)



py_gen = rule(
  implementation = _py_gen_imp,
  output_to_genfiles = True,
  attrs = {
    "name" : attr.string(default = "jun", mandatory = False)
  }
)