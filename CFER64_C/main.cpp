#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> x;

    for (int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        x.push_back(tmp);
    }


    vector<long long> p;

    for (int i = 0; i < m; i++) {
        long long tmp;
        cin >> tmp;
        p.push_back(tmp);
    }


    long long q = x[1] - x[0];

    for (int i = 2; i < n; i++) {
        q = __gcd(q, x[i] - x[0]);
    }

    for (int i = 0; i < m; i++) {
        if (q % p[i] == 0) {
            cout << "YES" << endl;
            cout << x[0] << " " << i + 1;
            return 0;
        }
    }

    cout << "NO";

    return 0;
}