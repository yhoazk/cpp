import pytest
import subprocess
import psutil 
import sys, os
import re
import logging

def test_logger(capsys, tmpdir):
    logging.error(os.listdir("."))
    bin_dir = str(os.path.dirname(os.readlink("logger_generator")))
    print(os.readlink("logger_generator"))
    #with open("log_gen") as log:
    app = "logger_generator"
    # we need to get the real location as the logger app is a link
    # it will be possible to acces the link src as its outside of
    # the binded dirs
    cmd = """/usr/bin/bwrap \
    --ro-bind /usr /usr  \
    --ro-bind {bin_dir} /bin \
    --symlink usr/lib64 /lib64 \
    --proc /proc \
    --dev /dev \
    --unshare-pid \
    /bin/logger_generator""".format(bin_dir=bin_dir, app=app).split() #ls -athl /bin/logger_generator

    logger = subprocess.Popen(cmd, stdout=subprocess.PIPE)
    out,err=logger.communicate()
    # Communicate returns a bunch of bytes, we need to parse them to ascii
    out = [l.decode("ascii") for l in out.splitlines()]
    logged_text = []
    print("-------- Out --------")
    for l in out:
        res = re.match("thid:(\d+)\s+N:\s+(\d+)", l)
        if res is not None and len(res.groups()) > 0:
            print("all={}  n: {} id: {}".format(res.group(0), res.group(1), res.group(2)) )
            logged_text.append(int(res.group(2)))
        else:
            print("Malformed log: {}".format(l))
    print("-------- Out --------")

    print("-------- Err --------")
    print(err)
    print("-------- Err --------")
    print(sorted(logged_text))
    assert False

def test_logg_fail():
    assert True

if __name__ == "__main__":
    sys.exit(pytest.main([__file__]))