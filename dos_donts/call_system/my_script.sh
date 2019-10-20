#!/usr/bin/bash 

# this script will be called several times, but it will fail in the flock part
## getting the error status of a subshell
## https://blog.famzah.net/2013/07/31/using-flock-in-bash-without-invoking-a-subshell/
(
    flock  -n 999 || exit
    ## this script will call other binaries with different and network configs
    ## how to keep track of this?
    ./another_script.sh &
    wait $! && exit $?
) 999>/tmp/dhcpc_lock
exit $? # This is the value seen by the c++ program, which comes from the subshell