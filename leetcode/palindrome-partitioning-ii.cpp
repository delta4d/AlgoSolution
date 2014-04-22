// 164ms
// dp
const int N = 2000;
bool isp[N][N];
int f[N];
class Solution {
public:
    void init(string &s, int n) {
        memset(isp, false, sizeof(isp));
        for (int i=0; i<n; ++i) isp[i][i] = true;
        for (int k=1; k<n; ++k) {
            for (int i=0; i+k<n; ++i) {
                int j = i + k;
                if (s[i] == s[j]) isp[i][j] = i + 2 <= j ? isp[i+1][j-1] : true;
            }
        }
    }
    int _m(string &s, int n) {
        for (int i=0; i<n; ++i) {
            if (isp[0][i]) {
                f[i] = 0;
            } else {
                f[i] = n;
                for (int j=i; j>0; --j) if (isp[j][i]) {
                    f[i] = min(f[i], f[j-1] + 1);
                }
            }
        }
        return f[n-1];
    }
    int minCut(string s) {
        int n = (int)s.length();
        init(s, n);
        return _m(s, n);
    }
};
