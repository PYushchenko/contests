#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> a;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back({tmp, i});
    }

    sort(a.begin(), a.end());

    for (int i=0; i<n; i++) {

    }


    return 0;
}