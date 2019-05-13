def find_point(l1, r1, l2, r2):
    if (l1 == l2):
        yield l1 + 1
    else:
        yield l1
    if (l1 == l2):
        yield l2
    else:
        yield l2


n = int(input())
for i in range(n):
    l1, r1, l2, r2 = [int(x) for x in input().split()]
    x1, x2 = find_point(l1, r1, l2, r2)
    print(x1,x2)