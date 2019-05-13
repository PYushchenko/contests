#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void no() {
    cout << "NO";
}

int main() {
    int n;
    cin >> n;
    vector<string> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (a[i][j] == '.') {
                a[i][j] = '#';
                if (a[i + 1][j - 1] == '#') {
                    no();
                    return 0;
                } else {
                    a[i + 1][j - 1] = '#';
                }
                if (a[i + 1][j] == '#') {
                    no();
                    return 0;
                } else {
                    a[i + 1][j] = '#';
                }
                if (a[i + 1][j + 1] == '#') {
                    no();
                    return 0;
                } else {
                    a[i + 1][j + 1] = '#';
                }
                if (a[i + 2][j] == '#') {
                    no();
                    return 0;
                } else {
                    a[i + 2][j] = '#';
                }

            }
        }
    }
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '.') {
                no();
                return 0;
            }
        }
    }

    cout << "YES";

    return 0;
}