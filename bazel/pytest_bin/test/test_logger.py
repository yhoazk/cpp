import pytest
import subprocess
import bubblewrap
import sys, os


def test_logger():
    print(os.listdir("."))
    logger = subprocess.Popen("logger_generator")
    logger.communicate()
    assert True

def test_logg_fail():
    assert False

test_logger()
test_logg_fail()