// 4ms
// simulation
class Solution {
public:
    string _g(const int L, int &cnt, int &len, vector <string> &cc, bool last) {
        string ret;
        if (cnt == 1) {
            ret = cc.front();
            for (int i=L-cc.front().length(); i>0; --i) ret += " ";
        } else {
            int avg = (L - len) / (cnt - 1), rem = (L - len) % (cnt - 1);
            for (int i=0; i<cnt; ++i) {
                ret += cc[i];
                if (i == cnt - 1) break;
                ret += " ";
                if (!last) {
                    for (int j=1; j<avg; ++j) ret += " ";
                    if (i < rem) ret += " ";
                }
            }
        }
        ret.resize(L, ' ');
        cnt = 0, len = 0, cc.clear();
        return ret;
    }
    vector<string> fullJustify(vector<string> &words, int L) {
        vector <string> ret, cc;
        int cnt = 0, tot = 0;
        for (auto &w: words) {
            int len = (int)w.length();
            if (tot + len + cnt > L) {
                ret.push_back(_g(L, cnt, tot, cc, false));
            }
            tot += len, ++cnt;
            cc.push_back(w);
        }
        ret.push_back(_g(L, cnt, tot, cc, true));
        return ret;
    }
};
