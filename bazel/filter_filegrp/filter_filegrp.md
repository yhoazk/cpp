# Bazel filter generated filegroup

A generator receives the configuration and then outputs a set of files
normally this files would be grouped in a single `file_group`.
The use case here is to avoid running the generator multiple times and
also allow users which do not need the separated output work without any
modification
