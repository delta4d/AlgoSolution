// 168ms
// be greedy!
const int N = 100086;
int pi[N];
char ts[N], tp[N];
#define _cp(x, y) ((x) == '?' || (x) == (y))
int kmp(char s[], int ls, char p[], int lp) {
	int i, k;
	for (pi[0]=-1,i=1; i<lp; ++i) {
		for (k=pi[i-1]; k>=0&&!_cp(p[k+1],p[i]); k=pi[k]);
		pi[i] = _cp(p[k+1], p[i]) ? k + 1 : -1;
	}
	for (k=-1,i=0; i<ls; ++i) {
		for (; k>=0&&!_cp(p[k+1],s[i]); k=pi[k]);
		if (_cp(p[k+1], s[i])) ++k;
		if (k == lp - 1) return i - k;
	}
	return -1;
}
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        char tok[] = "*", *cp = NULL;
        int ls = (int)strlen(s), lp = (int)strlen(p), len, cnt = 0;
        if (!ls && !lp) return true;
        if (!lp) return false;
        int first = -1, last = 0;
        char p0 = p[0], pn = p[lp-1];
        strcpy(ts, s), strcpy(tp, p);
		for (int i=0; i<lp; ++i) cnt += tp[i] == '*';
        for (cp=strtok(tp, tok); cp!=NULL; cp=strtok(NULL, tok)) {
            len = (int)strlen(cp);
            if (len == 0) continue;
            int pos = kmp(ts+last, ls-last, cp, len);
            if (pos == -1) return false;
            if (first == -1) first = pos;
            last = pos + len + last;
        }
        if (p0 != '*' && first) return false;
		if (pn == '*') return true;
		if (cnt) {
			for (int i=0; i<len; ++i) if (!_cp(p[lp-i-1], s[ls-i-1])) return false;
			return true;
		}
        return last == ls;
    }
};
