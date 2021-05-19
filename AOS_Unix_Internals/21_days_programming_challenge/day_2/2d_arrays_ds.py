# https://www.hackerrank.com/challenges/2d-array/problem
# !/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'hourglassSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#


def hourglassSum(arr):
    # Write your code here
    out = -100
    res = 0
    for i in range(4):
        for j in range(4):
            res = 0
            res = res + arr[i][j]
            res = res + arr[i][j+1]
            res = res + arr[i][j+2]
            res = res + arr[i+1][j+1]
            res = res + arr[i+2][j]
            res = res + arr[i+2][j+1]
            res = res + arr[i+2][j+2]
            if res > out:
                out = res
    return out


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
