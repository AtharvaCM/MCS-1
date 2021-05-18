# https://www.hackerrank.com/challenges/diagonal-difference/problem
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'diagonalDifference' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#


def diagonalDifference(arr):
    # Write your code here
    ld = 0
    rd = 0
    j = len(arr) - 1
    for i in range(len(arr)):
        ld = ld + arr[i][i]
        rd = rd + arr[i][j]
        j = j - 1
    return abs(ld - rd)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
