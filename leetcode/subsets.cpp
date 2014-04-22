// 16ms
// bit operation
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int n = (int)S.size();
        vector <vector <int>> ret;
        assert(n < 32);
        sort(begin(S), end(S));
        for (int mask=(1<<n)-1; mask>=0; --mask) {
            vector <int> cc;
            for (int i=0; i<n; ++i) if (mask & 1 << i) {
                cc.push_back(S[i]);
            }
            ret.push_back(cc);
        }
        return ret;
    }
};
