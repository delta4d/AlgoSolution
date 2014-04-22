// 264ms
// bruteforce
class Solution {
public:
    bool _isp(string &s, int n) {
        for (int i=0; i+i<n; ++i) if (s[i] != s[n-1-i]) return false;
        return true;
    }
    vector <vector <string>> _p(string &s, int a, int b) {
        if (a > b) return {};
        vector <vector <string>> ret, cc;
        string ss = "";
        for (int i=a; i<=b; ++i) {
            ss += s[i];
            if (_isp(ss, i-a+1)) {
                cc = _p(s, i+1, b);
                for (auto &c: cc) {
                    ret.push_back({ss});
                    ret.back().insert(end(ret.back()), begin(c), end(c));
                }
                if (cc.empty()) ret.push_back({ss});
            }
        }
        return ret;
    }
    vector<vector<string>> partition(string s) {
        if (s.empty()) return {};
        int n = (int)s.length();
        return _p(s, 0, n-1);
    }
};
