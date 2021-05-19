# https://www.hackerrank.com/challenges/plus-minus/problem
# !/bin/python3

import math
import os
import random
import re
import sys

# Complete the plusMinus function below.


def plusMinus(arr):
    po, ne, ze = 0, 0, 0
    for i in range(len(arr)):
        if arr[i] > 0:
            po = po + 1
        elif arr[i] < 0:
            ne = ne + 1
        else:
            ze = ze + 1
    print(round(po / len(arr), 6))
    print(round(ne / len(arr), 6))
    print(round(ze / len(arr), 6))


if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
