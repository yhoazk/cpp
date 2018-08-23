import pytest
import subprocess
import bubblewrap



def test_logger():
    logger = subprocess.Popen("src/logger_generator")
    logger.communicate()