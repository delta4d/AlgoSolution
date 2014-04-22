// 56ms
// dp
const int MAXN = 10086;
int f[2][MAXN];

class Solution {
public:
    int numDistinct(string S, string T) {
        int ls = (int)S.length(), lt = (int)T.length();
        int cur = 0, nxt = 1;
        fill(f[0], f[0]+MAXN, 0);
        f[0][0] = 1;
        for (int i=1; i<=ls; ++i,cur=nxt,nxt=cur^1) for (int j=0; j<=lt; ++j) {
            f[nxt][j] = f[cur][j];
            if (S[i-1] == T[j-1]) f[nxt][j] += f[cur][j-1];
        }
        return f[cur][lt];
    }
};
