#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
class OneHandSort {
public:
    vector <int> sortShelf(vector <int> target) {
        map<int, int> m;
        vector <int> res;
        for (int i = 0; i < target.size(); i++) {
            m[target[i]] = i;
        }

        for (int i = 0; i < target.size(); i++) {
            if (target[i] != i) {
                int start = target[i];
                int pos = i;
                res.push_back(i);
                while(start != pos) {
                    target[pos] = pos;
                    pos = m[pos];
                    res.push_back(pos);
                }
                res.push_back(target.size());
                target[pos] = pos;
            }
        }
        return res;
    }
};

int main() {
    OneHandSort().sortShelf({1, 0, 3, 2});
    std::cout << "Hello, World!" << std::endl;
    return 0;
}