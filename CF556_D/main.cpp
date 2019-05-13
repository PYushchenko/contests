#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <map>
#include <set>

using namespace std;


bool check(map<char, set<int>> w, string a, string b, string c) {
    map<int, map<char, vector<int>>> ww;

    map<int, string> ss;
    ss[1] = a;
    ss[2] = b;
    ss[3] = c;

    bool res = true;

    for (int y = 1; y <= 3; y++) {
        for (int j = 0; j < ss[y].size(); j++) {
            int m = 0;
            if (j != 0) {
                m = ww[y][ss[y][j - 1]].back();
            }
            auto it = w[ss[y][j]].lower_bound(m);
            if (it == w[ss[y][j]].end()) {
                res = false;
            } else {
                ww[y][ss[y][j]].push_back(*it);
                w[ss[y][j]].erase(it);
            }
        }
    }
    for (auto it1 : ww) {
        for (auto it2 : it1.second) {
            for (auto it3: it2.second) {
                w[it2.first].insert(it3);
            }
        }
    }
    return res;
}

int main() {
    int n, q;
    string s;
    cin >> n>> q;
    cin >>s;

    vector<vector<int>> w = vector<vector<int>>(s.size() + 1, vector<int>(26, INT_MAX));
    string a_s;
    map<int, string> ss;

    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = 0; j <= 26; j++) {
            w[i][j] = w[i + 1][j];
        }
        w[i][s[i] - 'a'] = i;
    }

    for (int i = 0; i < q; i++) {
        char t;
        cin >> t;
        if (t == '+') {

        } else {

        }
    }

    return 0;
}