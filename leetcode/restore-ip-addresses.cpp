// 8ms
// dfs, enumerate
class Solution {
public:
    bool ok(string &s, int st, int p, int c) {
        if (c < 0 || c > 255) return false;
        if (c == 0 && p > st) return false;
        if (s[st] == '0' && c > 0) return false;
        return true;
    }
    void dfs(int st, int d, string &cc, int n, string &s, vector <string> &ret) {
        if (d == 3) {
            int c = 0;
            for (int i=st; i<n; ++i) {
				c = c * 10 + s[i] - '0';
				cc[i+d] = s[i];
				if (!ok(s, st, i, c)) return;
			}
            ret.push_back(cc);
            return;
        }
        for (int i=st,c=0; i+3-d<n; ++i) {
            c = c * 10 + s[i] - '0';
			cc[i+d] = s[i];
            if (!ok(s, st, i, c)) break;
			cc[i+d+1] = '.';
            dfs(i+1, d+1, cc, n, s, ret);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int n = (int)s.length();
        vector <string> ret;
        string cc(n+3, '\0');
        dfs(0, 0, cc, n, s, ret);
        return ret;
    }
};
