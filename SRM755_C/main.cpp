    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>
    #include <map>

    using namespace std;

    class OneHandSort2 {
    public:
        int minMoves(int N, vector <int> targetPrefix, int a, int b) {
            vector<int> target;
            map<int, int> m;
            map<int, int> mm;
            for (int i = 0; i < N; i++) {
                mm[i] = i;
            }
            for (int i = 0; i < targetPrefix.size(); i++) {
                target.push_back(targetPrefix[i]);
                m[target[i]] = i;
                mm.erase(target[i]);
            }
            for (int i = targetPrefix.size(); i < N; i++) {
                long long tmp = ((long long) target[i - 1] * a + b) % N;
                auto it = mm.lower_bound(tmp);
                int x = -1;
                if (it != mm.end()) {
                    x = it->first;
                    if (x < tmp) x = tmp;
                } else {
                    x = mm.lower_bound(0)->first;
                }
                target.push_back(x);
                m[target[i]] = i;
                mm.erase(target[i]);
            }

            vector <int> res;
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
            return res.size();
        }
    };

int main() {
    OneHandSort2().minMoves(10, {3,7}, 1664525, 1013904223);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}