// 96ms
// dp
const int MAXN = 1 << 10;
int f[MAXN][MAXN];
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = (int)word1.length(), l2 = (int)word2.length();
        for (int i=0; i<=l1; ++i) f[i][0] = i;
        for (int i=0; i<=l2; ++i) f[0][i] = i;
        for (int i=0; i<l1; ++i) for (int j=0; j<l2; ++j) {
            if (word1[i] == word2[j]) {
                f[i+1][j+1] = f[i][j];
            } else {
                f[i+1][j+1] = min(f[i][j], min(f[i][j+1], f[i+1][j])) + 1;
            }
        }
        return f[l1][l2];
    }
};
