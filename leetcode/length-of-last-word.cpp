// 8ms
// simulation
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int n = strlen(s), i, j;
        for (i=n-1; i>=0&&s[i]==' '; --i);
        if (i < 0) return 0;
        for (j=i; j>=0&&s[j]!=' '; --j);
        return i - j;
    }
};
