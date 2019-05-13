n, m = [int(x) for x in input().split()]

a = [int(x) for x in input().split()]

a.sort()
last = 0
total = 0
for i in range(n - 1):
    if a[i]>0 :
        total += a[i] - 1
        last = min(last + 1, a[i])

print(total + max(a[n-1] - max(1, a[n - 1] - last), 0))