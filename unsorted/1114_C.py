n, b = [int(x) for x in input().split()]

def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

def count_k_p(n ,p):
    i = p
    sum = 0
    while i <= n:
        sum += n // i
        i *= p
    return sum

import math
k = math.inf

# print(prime_factors(n))

prime_factors_list = prime_factors(b)
prime_factors_set = set(prime_factors_list)

for i in prime_factors_set:
    # print(prime_factors_list.count(i))
    # print("k_p for " , i , count_k_p(n,i))
    k = min(k, count_k_p(n, i) // prime_factors_list.count(i))

print(k)