#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m ,r;
    cin >> n >> m >> r;

    vector<int> s, b;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        s.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    sort(s.begin(), s.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    if (s[0] >= b[0]) {
        cout << r;
        return 0;
    }

    int count = r / s[0];

    int left = r % s[0];

    int res = count * b[0];

    cout << res +  left;

    return 0;
}
