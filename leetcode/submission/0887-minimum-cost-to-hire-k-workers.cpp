class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
                double res = 1e18;
        
        vector<pair<double, int>> rate;
        for (int i = 0; i < wage.size(); i++) {
            rate.push_back({(double) wage[i] / quality[i], i});
        }
        sort(rate.begin(), rate.end());

        priority_queue<double> q;
        int sumq = 0;
        for (int i = 0; i < rate.size(); i++) {
            q.push(quality[rate[i].second]);
            sumq += quality[rate[i].second];
            if (q.size() > K) {
                sumq -= q.top();
                q.pop();
            }
            if (q.size() == K) {
                res = min(res, sumq * rate[i].first);
            }
        }
        return res;
    }
};
