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
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval & a, const Interval & b)->bool{
            if (a.start != b.start) {
                return a.start < b.start;
            }
            return a.end < b.end;
        });
        vector<Interval> ans;
        Interval tmp(-2147483647, -2147483647);
        for (auto &inte : intervals) {
            if (inte.start > tmp.end) {
                if (tmp.end > -2147483647) {
                    ans.push_back(tmp);
                }
                tmp = inte;
            } else {
                tmp.end = max(tmp.end, inte.end);
            }
        }
        if (tmp.end > -2147483647) {
            ans.push_back(tmp);
        }
        return ans;
    }
};
