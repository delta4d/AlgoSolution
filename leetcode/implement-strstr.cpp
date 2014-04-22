// 52ms
// kmp algorithm [O(n)]
// pay attention to the pattern string begin empty ""
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        const int MAXN = 1e6 + 86;
        int pi[MAXN], i, j;
        int lh = strlen(haystack), ln = strlen(needle);
        if (ln == 0) return haystack;
        for (pi[0]=-1,i=1; i<ln; ++i) {
            for (j=pi[i-1]; j>=0&&needle[i]!=needle[j+1]; j=pi[j]);
            pi[i] = needle[i] == needle[j+1] ? j + 1 : -1;
        }
        for (i=0,j=-1; i<lh; ++i) {
            for (; j>=0&&haystack[i]!=needle[j+1]; j=pi[j]);
            j = haystack[i] == needle[j+1] ? j + 1 : -1;
            if (j == ln - 1) return haystack + i - j;
        }
        return NULL;
    }
};
