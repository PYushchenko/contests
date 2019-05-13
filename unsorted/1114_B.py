n, m, k = [int(x) for x in input().split()]
a = [int(x)  for x in input().split()]

b = sorted(range(len(a)), key=lambda k: a[k])
b.reverse()

b = b[:m*k]

b.sort()

sum = 0
print(b)

for i in b:
    sum += a[i]

print(sum)
b = b[m - 1:-1:m]

for i in b:
    print(i + 1)