n = int(input())
a = [int(x) for x in input().split()]

b = [[0 for i in range(n + 1)] for j in range(n + 1)]

if a.count(a[0]) == len(a):
    print(0)
    exit()

import math

for i in range(0, n + 1):
    for j in range(0, n + 1):
        if i > 1:
            if a[i - 1] == a[i - 2]:
                left = b[i - 1][j]
            else:
                left = b[i - 1][j] + 1
        elif i == 1:
            left = right = b[i - 1][j] + 1
        else:
            left = math.inf
        if j > 1:
            if a[n - j] == a[n - j + 1]:
                right = b[i][j - 1]
            else:
                right = b[i][j - 1] + 1
        elif j == 1:
            right = b[i][j - 1] + 1
        else:
            right = math.inf
        if i > 1 and j > 1 and a[i - 1] == a[n - j] and (a[n - j] == a[n - j + 1] or a[i - 1] == a[i - 2]):
            middle = b[i-1][j-1]
        elif i > 1 and j > 1 and a[i - 1] == a[n - j]:
            middle = b[i-1][j-1] + 1
        else:
            middle = math.inf
        if i == 0 and j == 0:
            b[0][0] = 0
        else:
            b[i][j] = min(left, right)
            b[i][j] = min(b[i][j], middle)

for x in b:
    print(x)

res = math.inf
for i in range(n):
    res = min(res, b[i][n - i - 1])

print(res)