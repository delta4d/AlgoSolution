// 20ms
// basic string operation
class Solution {
public:
    void reverseWords(string &s) {
        string t, w;
        for (int i=(int)s.length()-1; i>=-1; --i) {
            if (i == -1 || s[i] == ' ') {
                if (!w.empty()) {
                    reverse(begin(w), end(w));
                    if (!t.empty()) t += ' ';
                    t += w;
                    w.clear();
                }
            } else {
                w += s[i];
            }
        }
        s = t;
    }
};

/**
// 144ms
// python
class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        return " ".join(s.split()[::-1])
**/
