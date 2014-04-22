// 236ms
// two-pointers
class Solution {
public:
    string minWindow(string S, string T) {
        string ret;
        int ls = (int)S.length(), lt = (int)T.length();
        int rem[256] = {0}, tot = lt;
        if (ls < lt) return ret;
        for (int i=0; i<lt; ++i) ++rem[T[i]];
        for (int i=0,j=0; j<ls; ++j) {
            --rem[S[j]];
            if (rem[S[j]] >= 0) --tot;
            while (tot == 0 && i <= j) {
                string c = S.substr(i, j-i+1);
                if (ret.empty() || (int)c.length() < (int)ret.length()) ret = c;
                ++rem[S[i]];
                if (rem[S[i]] > 0) ++tot;
                ++i;
            }
        }
        return ret;
    }
};
