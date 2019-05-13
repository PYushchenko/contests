n = int(input())
a = [int(x) for x in input().split()]

a.sort(reverse=True)
x = a[0]
y = 1
for i in a:
    if x % i != 0:
        print(x, i)
        exit()
print(x, 1)