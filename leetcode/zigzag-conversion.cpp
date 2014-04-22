// 148ms
// simulation
class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        string ret;
        vector <string> tmp(nRows);
        int m = (nRows - 1) << 1, len = (int)s.length();
        for (int i=0; i<len; ++i) {
            int r = i % m;
            if (r >= nRows) r -= m;
            tmp[abs(r)].push_back(s[i]);
        }
        for (int i=0; i<nRows; ++i) ret += tmp[i];
        return ret;
    }
};
