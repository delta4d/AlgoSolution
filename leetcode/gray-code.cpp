// 12ms
class Solution {
public:
    void _g(int d, int n, vector <int> &ret) {
        if (d == n) return;
        vector <int> tmp = ret;
        for (int i=(int)ret.size()-1; i>=0; --i) {
            tmp[i] ^= 1 << d;
        }
        reverse(begin(tmp), end(tmp));
        ret.insert(end(ret), begin(tmp), end(tmp));
        _g(d+1, n, ret);
    }
    vector<int> grayCode(int n) {
        vector <int> ret = {0};
        _g(0, n, ret);
        return ret;
    }
};
