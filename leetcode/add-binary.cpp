// 44ms
// simulation
#define bit(x, i, lx) (i < lx ? (x[i] - '0') : 0)
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));
        int la = (int)a.length(), lb = (int)b.length();
        vector <int> tmp(max(la, lb) + 1, 0);
        for (int i=0; i<la||i<lb; ++i) tmp[i] = bit(a, i, la) + bit(b, i, lb);
        for (int i=0; i<la||i<lb; ++i) {
            tmp[i+1] += tmp[i] >> 1;
            tmp[i] &= 1;
        }
        for (; (int)tmp.size()>1&&tmp.back()==0; tmp.pop_back());
        string ret;
        for (int i=(int)tmp.size()-1; i>=0; --i) ret += char(tmp[i] + '0');
        return ret;
    }
};
