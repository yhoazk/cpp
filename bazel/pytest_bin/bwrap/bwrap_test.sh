#!/usr/bin/env bash

#strace /usr/bin/bwrap --ro-bind /usr /usr --dev /dev --proc /proc --setenv PATH $HOME --ro-bind $HOME $HOME --unshare-all --hostname test $HOME/workspace/cpp/bazel/pytest_bin/bwrap/simple_app/simple_app.exe
bwrap --ro-bind /usr /usr --ro-bind /home/porko/workspace/cpp/for_each/ /hom --symlink usr/lib64 /lib64 --proc /proc --dev /dev --unshare-pid /hom/for_each.exe