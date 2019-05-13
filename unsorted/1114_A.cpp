#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <assert.h>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<long long> a;
    vector<long long> b;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    long long count = 0;
    long long last = -n * 2;
    for (int i = 0; i < n; i++) {
        b.push_back(count);
        if (a[i] > last + n) {
            count += n;
            last = a[i] + n;
        } else {
            count += a[i] + n - last;
            last = a[i] + n;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    // int q;
    // cin >> q;
    // for (int i = 0; i < q; i++) {
    //     long long l,r;
    //     cin >> l >> r;
    //     long long res;



    //     cout << res << " ";
    // }

    return 0;
}