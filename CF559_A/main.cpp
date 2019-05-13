#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long count = 0;

    for (long long i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') count++;
        if (c == '-') count--;
        if (count < 0) {
            count++;
        }
    }

    cout << count;

    return 0;
}