class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for (auto email : emails) {
            string local = email.substr(0, email.find('@'));
            string domain = email.substr(email.find('@'));
            auto plus = local.find('+');
            if (plus != string::npos) {
                local = local.substr(0, plus);
            }
            local.erase(remove(local.begin(), local.end(), '.'), local.end());
            s.insert(local + domain);
        }        
        return s.size();
    }
};
