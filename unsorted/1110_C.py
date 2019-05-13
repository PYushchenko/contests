from operator import xor
import math

q = int(input())

def computeGCD(x, y):
    while (y):
        x, y = y, x % y
    return x


def guess_d(x):
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return x // i
    # return 1


for j in range(2, q):
    a = j
    print(j)

    correct = 0

    # for i in range(1, a):
    #     correct = max(correct, computeGCD(xor(i, a), i & a))
    #     # print(i, correct, xor(i, q), i & q)

    guess_b = 0
    pow = 1
    tmp = a
    while tmp:
        guess_b += ((tmp % 2 + 1) % 2 ) * pow
        pow *= 2
        tmp = tmp // 2

    if guess_b == 0:
        guess_b = guess_d(a)

    guess = computeGCD(xor(guess_b, a), guess_b & a)

    print(guess)