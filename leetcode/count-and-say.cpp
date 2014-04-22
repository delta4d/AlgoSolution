// 40ms
// simulation
class Solution {
public:
    string to_s(int x) {
        char buf[80];
        sprintf(buf, "%d", x);
        return string(buf);
    }
    string countAndSay(int n) {
        string ret = "1";
        for (int i=1; i<n; ++i) {
            string tmp;
            for (int i=1,l=(int)ret.length(),c=1; i<=l; ++i) {
                if (i == l || ret[i] != ret[i-1]) {
                    tmp += to_s(c);
                    tmp += ret[i-1];
                    c = 1;
                } else {
                    ++c;
                }
            }
            ret.swap(tmp);
        }
        return ret;
    }
};
