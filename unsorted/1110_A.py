b, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

b_odd = b % 2

sum = 0

for i in range(k - 1):
    sum += a[i]*b_odd

sum += a[k - 1]
# print(sum)

if sum % 2:
    print("odd")
else:
    print("even")