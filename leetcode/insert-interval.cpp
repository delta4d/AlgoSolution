// 68ms
// one-run O(n)
class Solution {
public:
    bool inter(Interval &a, Interval &ret) {
        if (max(a.start, ret.start) > min(a.end, ret.end)) return false;
        ret.start = min(ret.start, a.start), ret.end = max(ret.end, a.end);
        return true;
    }
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if (intervals.empty()) return {newInterval};
        vector <Interval> ret;
        bool merged{};
        for (auto &p: intervals) {
            if (!inter(p, newInterval)) {
                if (p.start > newInterval.end && !merged) {
                    ret.push_back(newInterval); 
                    merged = true;
                }
                ret.push_back(p);
            }
        }
        if (!merged) ret.push_back(newInterval);
        return ret;
    }
};

// 80ms
// binary search
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool operator<(const Interval &a, const Interval &b) {
	if (a.start != b.start) return a.start < b.start;
	return a.end < b.end;
}
const int INF = 0x3f3f3f3f;
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int st = newInterval.start, ed = newInterval.end;
        int lp = lower_bound(begin(intervals), end(intervals), Interval(st, st)) - begin(intervals);
        int rp = upper_bound(begin(intervals), end(intervals), Interval(ed, INF)) - begin(intervals);
        int L = st, R = ed;
        vector <Interval> ret;
        if (lp > 0 && intervals[lp-1].start <= st && st <= intervals[lp-1].end) L = intervals[--lp].start;
        if (rp > 0 && intervals[rp-1].start <= ed && ed <= intervals[rp-1].end) R = intervals[rp-1].end;
        for (int i=0; i<lp; ++i) ret.push_back(intervals[i]);
        ret.push_back(Interval(L, R));
        for (int i=rp; i<(int)intervals.size(); ++i) ret.push_back(intervals[i]);
        return ret;
    }
};
