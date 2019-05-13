import math

n = int(input())
a = [int(i) for i in input().split()]

a.sort()

result = 0

for i in range(n // 2):
    result += (a[i] + a[n - i - 1])**2

print(result)