// 40ms
// math, O(n)
// from k start
// dis[i] = S[i] + S[n] - S[k] (i <= k)
//        = S[i] - S[k]        (i > k)
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = (int)gas.size();
        vector <int> S(n), pre(n), suf(n);
        for (int i=0; i<n; ++i) S[i] = gas[i] - cost[i];
        partial_sum(begin(S), end(S), begin(S), plus<int>());
        pre[0] = S[0];
        for (int i=1; i<n; ++i) pre[i] = min(pre[i-1], S[i]);
        suf[n-1] = S[n-1];
        for (int i=n-2; i>=0; --i) suf[i] = min(suf[i+1], S[i]);
        if (pre[n-1] >= 0) return 0;
        for (int i=0; i+1<n; ++i) {
            int cc = min(pre[i] + S[n-1] - S[i], suf[i+1] - S[i]);
            if (cc >= 0) return i + 1;
        }
        return -1;
    }
};
