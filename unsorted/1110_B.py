n, m, k = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

a = []

for i in range(1, n):
    a.append((b[i] - b[i-1], i))

a.sort()

used = set()

sum = 0
count = 0

if k >= n:
    print(n)
    exit()

for i in range(n - 1):
    count += 1
    sum += a[i][0]
    if a[i][1] not in used and a[i][1] + 1 not in used:
        sum += 1
    else:
        count -= 1

    used.add(a[i][1])
    used.add(a[i][1] + 1)

    if (len(used) + k - count == n):
        break

print(sum + k - count)