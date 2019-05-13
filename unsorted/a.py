n, s = [int(x) for x in input().split()]

count = 0
while True:
    k = min(s, n)
    count += s // k

    s = s % k

    if s == 0:
        break

print(count)