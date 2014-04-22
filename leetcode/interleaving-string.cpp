// 36ms
// basic dp
// ok(i, j): if s1[1..i] and s2[1..j] can form s3[1..i+j]
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = (int)s1.size(), l2 = (int)s2.size(), l3 = (int)s3.size();
        if (l1 + l2 != l3) return false;
        const int MAXN = 1 << 10;
        bool ok[MAXN][MAXN];
        ok[0][0] = true;
        for (int i=0; i<=l1; ++i) for (int j=0; j<=l2; ++j) {
            if (i + j == 0) continue;
            ok[i][j] = i >= 1 && s1[i-1] == s3[i+j-1] && ok[i-1][j]
                    || j >= 1 && s2[j-1] == s3[i+j-1] && ok[i][j-1];
        }
        return ok[l1][l2];
    }
};
