import pytest
import subprocess
import psutil 
import sys, os
import re

def test_logger(capsys):
    print(os.listdir("."))
    #with open("log_gen") as log:
    app = "logger_generator"

    cmd = """strace /usr/bin/bwrap \
    --dev-bind / /  \
    --setenv PATH . \
    {app}""".format(app=app).split()

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