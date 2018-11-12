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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        bool inserted = false;
        for (auto it = intervals.begin(); it != intervals.end(); it++) {
            if (it->end < newInterval.start || it->start > newInterval.end) {
                if (it->start > newInterval.end && !inserted) {
                    ans.push_back(newInterval);
                    inserted = true;
                }
                ans.push_back(*it);
            } else {
                if (it->start < newInterval.start) {
                    newInterval.start = it->start;
                }
                if (it->end > newInterval.end) {
                    newInterval.end = it->end;
                }
            }
        }
        if (!inserted) {
            ans.push_back(newInterval);
        }
        return ans;
    }
};
