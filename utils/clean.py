"""
清空temp里面的东西
"""

import os
import shutil


tempPath = "./leetcode/temp"


def clean():
    """清空temp里面的东西"""
    temp = os.path.join(os.path.dirname(__file__), '..', 'temp')
    if os.path.exists(temp):
        shutil.rmtree(temp)


if __name__ == "__main__":
    clean()
