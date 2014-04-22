// 28ms
// dfs
class Solution {
public:
    void _s(int d, const int n, vector <int> &cc, vector <vector<int>> &ret, vector <int> &S, vector <int> &cnt) {
        if (d == n) {
            ret.push_back(cc);
            return;
        }
        _s(d+1, n, cc, ret, S, cnt);
        for (int i=cnt[d]; i>0; --i) {
            cc.push_back(S[d]);
            _s(d+1, n, cc, ret, S, cnt);
        }
		for (int i=cnt[d]; i>0; --i) cc.pop_back();
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector <int> cnt, cc;
        vector <vector <int>> ret;
        sort(begin(S), end(S));
        int c = 1;
        for (int i=1; i<(int)S.size(); ++i) {
            if (S[i] != S[i-1]) {
                cnt.push_back(c);
                c = 1;
            } else {
                ++c;
            }
        }
        cnt.push_back(c);
        S.erase(unique(begin(S), end(S)), end(S));
        int n = (int)S.size();
        _s(0, n, cc, ret, S, cnt);
        return ret;
    }
};
