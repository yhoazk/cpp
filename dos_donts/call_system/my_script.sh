#!/usr/bin/bash 

# this script will be called several times, but it will fail in the flock part
(
    flock  -n 999 || exit
    ./another_script.sh &
) 999>/tmp/dhcpc_lock