n, m, k = [int() for i in input().split()]

a = []

for i in range(k):
    s, t, d, w = [int() for i in input().split()]
    a.append((s, t, d, w))

max = 100

result = [[0 for j in range(m)] for i in range(max)]

for t in range(max):
    for j in range(m):
# not disturb
        if result[t-1][j].d > t:
            selectnew(t)
        else:


