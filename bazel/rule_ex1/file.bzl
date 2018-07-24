def __impl(ctx):
  output = ctx.outputs.out
  ctx.file_action(output = output, content = ctx.attr.content)

file = rule(implementation = __impl,
  attrs = {"content":attr.string()},
  outputs = {"out":"%{name}.txt"})
