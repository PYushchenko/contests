#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;


vector<int> sieve(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    vector<int> res;

    // Print all prime numbers
    for (int p=2; p<=n; p++)
        if (prime[p])
            res.push_back(p);

    return res;
}

int main() {
    int n;

    cin >> n;

    int count_1 = 0;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) count_1++;
    }

    int count_2 = n - count_1;

    auto primes = sieve(count_1 + count_2 * 2 + 100);

    int sum = 0;

    for (auto x : primes) {
        int q = x - sum;
        int m = min(q / 2, count_2);
        for (int i = 0; i < m; i++) {
            cout << 2 << " ";
        }
        sum += m * 2;
        q -= m * 2;
        count_2 -= m;

        m = min(q, count_1);

        for (int i = 0; i < m; i++) {
            cout << 1 << " ";
        }
        sum += m;
        q -= m;
        count_1 -= m;

        if (count_2 == 0 and count_1 == 0) {
            return 0;
        }
    }

    return 0;
}