// 140ms
class Solution {
public:
    void dfs(int d, const int n, int rem, vector <int> &cc, vector <vector <int>> &ret, vector <int> &x) {
        if (!rem) {
            ret.push_back(cc);
            return;
        }
        if (d == n) return;
        int sz = (int)cc.size();
        for (int tt=rem; tt>=0; tt-=x[d]) {
            dfs(d+1, n, tt, cc, ret, x);
            cc.push_back(x[d]);
        }
        cc.resize(sz);
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int n = (int)candidates.size();
        vector <int> cc;
        vector <vector <int>> ret;
        sort(begin(candidates), end(candidates));
        dfs(0, n, target, cc, ret, candidates);
        return ret;
    }
};
