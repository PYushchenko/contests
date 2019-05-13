#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;

    cin >> s;

    int count = 0;

    for (int i = 0; i < s.size() - 10; i++) {
        if (s[i] == '8') {
            count++;
        }
    }

    if (count > (n - 11) / 2) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}