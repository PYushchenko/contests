n,m = [int(i) for i in input().split()]

a = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]

sorted = [i[0] for i in sorted(enumerate(c), key=lambda x:x[1])]

chipest = 0

for i in range(m):
    result = 0
    t,d = [int(i) for i in input().split()]

    t -= 1

    if d < a[t]:
        result += c[t] * d
        a[t] -= d
        d = 0
    else:
        result += c[t] * a[t]
        d -= a[t]
        a[t] = 0

        while d != 0:
            if chipest >= n:
                result = 0
                break

            if d < a[sorted[chipest]]:
                result += c[sorted[chipest]] * d
                a[sorted[chipest]] -= d
                d = 0
            else:
                result += c[sorted[chipest]] * a[sorted[chipest]]
                d -= a[sorted[chipest]]
                a[sorted[chipest]] = 0
                chipest += 1

    print(result)

