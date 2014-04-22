// 104ms
// recursive
// c++ itself have regex lib, it seems the OJ disables it
class Solution {
public:
    bool wildchar(const char x) {
        return x == '.' || x == '*';
    }
    bool _match(const char *s, int ss, int ls, const char *p, int sp, int lp) {
        if (ss == ls && sp == lp) return true;
        if (!wildchar(p[sp])) {
            if (p[sp+1] != '*') {
                if (s[ss] != p[sp]) return false;
                return _match(s, ss+1, ls, p, sp+1, lp);
            }
            // x*
            if (_match(s, ss, ls, p, sp+2, lp)) return true;
            for (; s[ss]==p[sp]; ++ss) {
                if (_match(s, ss+1, ls, p, sp+2, lp)) return true;
            }
            return false;
        }
        if (p[sp+1] == '*') { // .*
            for (; ss<=ls; ++ss) {
                if (_match(s, ss, ls, p, sp+2, lp)) return true;
            }
            return false;
        }
        return _match(s, ss+1, ls, p, sp+1, lp);
    }
    bool isMatch(const char *s, const char *p) {
        int ls = strlen(s), lp = strlen(p);
        return _match(s, 0, ls, p, 0, lp);
    }
};
