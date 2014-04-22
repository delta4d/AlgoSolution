// 84ms
// sort and merge
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
    bool _overlap(Interval &a, Interval &b) {
        int x = max(a.start, b.start), y = min(a.end, b.end);
        if (x > y) return false;
        a.start = min(a.start, b.start), a.end = max(a.end, b.end);
        return true;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        vector <Interval> ret;
        sort(begin(intervals), end(intervals), [](const Interval &a, const Interval &b) {
            if (a.start != b.start) return a.start < b.start;
            return a.end < b.end;
        });
        for (auto &i: intervals) {
            if (ret.empty()) {
                ret.push_back(i);
            } else {
                if (!_overlap(ret.back(), i)) ret.push_back(i);
            }
        }
        return ret;
    }
};
