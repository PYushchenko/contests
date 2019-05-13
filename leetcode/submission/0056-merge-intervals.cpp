/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool compInt(const Interval &x, const Interval &y) {
        return x.start < y.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return vector<Interval>();
        }
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), compInt);
        int left = intervals[0].start;
        int right = intervals[0].end;
        for (auto i: intervals) {
            if (i.start <= right) {
                if (i.end > right) {
                    right = i.end;
                }
            } else {
                res.push_back({left, right});
                left = i.start;
                right = i.end;
            }
        }
        res.push_back({left, right});
        return res;
    }
};
