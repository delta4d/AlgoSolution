// 16ms
// dfs
class Solution {
public:
    bool _s(int a1, int b1, string &s1, int a2, int b2, string &s2) {
        if (a1 > b1) return true;
        if (a1 == b1) return s1[a1] == s2[a2];
        if (s1.substr(a1, b1-a1+1) == s2.substr(a2, b2-a2+1)) return true;
        int cnt[26] = {0};
        for (int i=a1; i<=b1; ++i) ++cnt[s1[i]-'a'], --cnt[s2[i-a1+a2]-'a'];
        for (int i=0; i<26; ++i) if (cnt[i]) return false;
        for (int i=a1; i<b1; ++i) {
            if (_s(a1, i, s1, a2, a2-a1+i, s2) && _s(i+1, b1, s1, b2-b1+i+1, b2, s2)
            || _s(a1, i, s1, b2+a1-i, b2, s2) && _s(i+1, b1, s1, a2, a2+b1-i-1, s2)) return true;
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        int l1 = (int)s1.length(), l2 = (int)s2.length();
        if (l1 != l2) return false;
        return _s(0, l1-1, s1, 0, l1-1, s2);
    }
};
