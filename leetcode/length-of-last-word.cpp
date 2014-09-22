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

// one run
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == nullptr) return 0;
        int ret = 0;
        for (; *s; ++s) {
            if (isspace(*s)) ret = ret > 0 ? -ret : ret;
            else ret = ret < 0 ? 1 : ret + 1;
        }
        return abs(ret);
    }
};
