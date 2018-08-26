import pytest
import subprocess
import bubblewrap
import sys, os
import re

def test_logger(capsys):
    print(os.listdir("."))
    #with open("log_gen") as log:
    logger = subprocess.Popen("logger_generator", stdout=subprocess.PIPE)
    out,err=logger.communicate()
    # Communicate returns a bunch of bytes, we need to parse them to ascii
    out = [l.decode("ascii") for l in out.splitlines()]
    logged_text = []
    print("-------- Out --------")
    for l in out:
        res = re.findall("thid:\d+\s+N:\s+\d+", l)
        if len(res) == 1:
            print(res)
        else:
            print("Malformed log: {}".format(l))
    print("-------- Out --------")

    print("-------- Err --------")
    print(err)
    print("-------- Err --------")
    assert False

def test_logg_fail():
    assert True

if __name__ == "__main__":
    sys.exit(pytest.main([__file__]))