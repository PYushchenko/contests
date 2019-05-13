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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;
        for (auto i: intervals) {
            start.push_back(i.start);
            end.push_back(i.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int count = 0;
        int max = 0;
        int j = 0;
        for (int i = 0; i < start.size(); i++) {
            count++;
            while (end[j] <= start[i]) {
                j++;
                count--;
            }
            if (count > max) {
                max = count;
            }
        }
        return max;
    }
};
