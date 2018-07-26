#!/usr/bin/env bash

echo 'const char ff[] = "Mandril \n\n  .";'
# echo 'const char ff[] = "Mandril \n\n  .";' > foo.h # This command will fail unless we copy the result to $@ in the bazel script

