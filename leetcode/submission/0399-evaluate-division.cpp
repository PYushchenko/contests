class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string, int> m;
        int count = 0;
        for (int i = 0; i < equations.size(); i++) {
            if (m.find(equations[i].first) == m.end()) {
                m[equations[i].first] = count++;
            }
            if (m.find(equations[i].second) == m.end()) {
                m[equations[i].second] = count++;
            }
        }
        vector<vector<double>> a = vector<vector<double>>(m.size(), vector<double>(m.size(), 0));
        for (int i = 0; i < equations.size(); i++) {
            a[m[equations[i].first]][m[equations[i].second]] = values[i];
            a[m[equations[i].second]][m[equations[i].first]] = 1 / values[i];
        }
        for (int i = 0; i < m.size(); i++) {
            a[i][i] = 1;
        }        
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m.size(); j++) {
                for (int k = 0; k < m.size(); k++){
                    if (a[i][k] == 0) {
                        a[i][k] = a[i][j] * a[j][k];
                    }
                }
            }
        }
        
        vector<double> res;
        for (int i = 0; i < queries.size(); i++) {
            if (m.find(queries[i].first) == m.end()) {
                res.push_back(-1.0);
                continue;
            }
            if (m.find(queries[i].second) == m.end()) {
                res.push_back(-1.0);
                continue;
            }
            if (queries[i].first == queries[i].second) {
                res.push_back(1.0);
                continue;
            }
            if (a[m[queries[i].first]][m[queries[i].second]] == 0) {
                res.push_back(-1.0);
                continue;
            }
            res.push_back(a[m[queries[i].first]][m[queries[i].second]]);
        }
        return res;
    }
};
