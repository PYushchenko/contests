
n = int(input())
a = [int(x) for x in input().split()]
b = [[0] * n for i in range(n)]

print(a)

a[n-1][n-1] = 9
for row in a:
    print(' '.join([str(elem) for elem in row]))