class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        map<string, int> m;
        map<int, set<int>> mm;
        int count = 0;
        for (int i = 0; i < pairs.size(); i++) {
            if (m.find(pairs[i].first) == m.end()) {
                m[pairs[i].first] = count++;
            }
            if (m.find(pairs[i].second) == m.end()) {
                m[pairs[i].second] = count++;
            }
            mm[m[pairs[i].first]].insert(m[pairs[i].second]);
            mm[m[pairs[i].second]].insert(m[pairs[i].first]);
        }
        
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] == words2[i]) {
                continue;
            }
            auto it1 = m.find(words1[i]);
            auto it2 = m.find(words2[i]);
            if (it1 != m.end() and it2 != m.end()) {
                if (mm[m[words1[i]]].find(m[words2[i]]) == mm[m[words1[i]]].end()) {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        return true;
    }
};
