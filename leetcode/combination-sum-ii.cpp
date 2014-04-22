// 68ms
// same as I
class Solution {
public:
    void dfs(int d, const int n, int rem, vector <int> &cc, vector <vector <int>> &ret, vector <int> &x, vector <int> &cnt) {
        if (!rem) {
            ret.push_back(cc);
            return;
        }
        if (d == n) return;
        int sz = (int)cc.size();
        for (int i=cnt[d]; rem>=0&&i>=0; --i,rem-=x[d]) {
            dfs(d+1, n, rem, cc, ret, x, cnt);
            cc.push_back(x[d]);
        }
        cc.resize(sz);
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int n = (int)num.size();
        vector <int> cc, cnt;
        vector <vector <int>> ret;
        sort(begin(num), end(num));
        for (int i=1,c=1; i<=n; ++i) {
            if (i == n || num[i] != num[i-1]) {
                cnt.push_back(c);
                c = 1;
            } else {
                ++c;
            }
        }
        num.erase(unique(begin(num), end(num)), end(num));
        n = (int)num.size();
        dfs(0, n, target, cc, ret, num, cnt);
        return ret;
    }
};
