// 36ms
// basic dp
class Solution {
public:
    bool valid(char a) {
        return '1' <= a && a <= '9';
    }
    bool valid(char a, char b) {
        return a == '1' || a == '2' && '0' <= b && b <= '6';
    }
    int numDecodings(string s) {
        if (s.empty()) return 0;
        const int MAXN = 1e5 + 86;
        int f[MAXN], n = (int)s.length();
        f[0] = 1;
        for (int i=0; i<n; ++i) {
            f[i+1] = valid(s[i]) * f[i] + (i >= 1 && valid(s[i-1], s[i])) * f[i-1];
        }
        return f[n];
    }
};
