x, y, z = [int(x) for x in input().split()]
a, b, c = [int(x) for x in input().split()]


if x > a:
    print("NO")
    exit()
else:
    a -= x

if y > a + b:
    print("NO")
    exit()
else:
    if y <= a:
        a -= y
    else:
        y -= a
        a = 0
        b -= y

if z > a + b + c:
    print("NO")
    exit()
else:
    print("YES")
    exit()
