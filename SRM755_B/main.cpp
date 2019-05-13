#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class OneHandScheduling {
    string checkSchedule(vector <int> tStart, vector <int> tEnd) {
        int left = -1;
        vector<pair<int, int>> a;

        for (int i = 0; i < tStart.size(); i++) {
            a.push_back({tStart[i], tEnd[i]});
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < tStart.size(); i++) {
            if (a[i].first <= left) {
                return "impossible";
            } else {
                left = a[i].second;
            }
        }
        return "possible";
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}