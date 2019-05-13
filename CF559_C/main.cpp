#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a, b;
    set<long long> bb;

    for (int i = 0; i < n; i++) {
        int tmp = 0;
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        int tmp = 0;
        cin >> tmp;
        bb.insert(tmp);
        b.push_back(tmp);
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    long amin = a.back();
    long bmin = b.back();

    int i = 0, j = 0;
    long long count = 0;
    while (i < n and j < m) {
        if (a[i] > bmin) {
            cout << -1;
            return 0;
        } else {
            if (bb.find(b[j]) != bb.end()) {
                count += b[j];
            } else {
                count += a[i];
            }
            count += a[i] * (m - 1);
            bb.erase(a[i]);
        }
        j++;
        i++;
    }

    for (int ii = i; ii < n; ii++) {
        if (a[ii] > bmin) {
            cout << -1;
            return 0;
        } else {
            count += a[ii] * m;
        }
    }

    for (int jj = j; jj < m; jj++) {
        if (b[jj] < amin) {
            cout << -1;
            return 0;
        } else {
            if (bb.find(b[jj]) != bb.end()) {
                count += b[jj];
                count += amin * (n - 1);
            }
        }
    }


    cout << count;

    return 0;
}