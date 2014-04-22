// 244ms
// NASTY, not a good implementation
const char roman[] = "MDCLXVI";
const int val[] = {1000, 500, 100, 50, 10, 5, 1};
class Solution {
public:
    string _r(int d, int x) {
        if (d > 4 || x <= 0) return "";
        string ret = "";
        int n = x / val[d+1], r = (x % val[d+1]) / val[d+2], m = n >> 1;
        if (r == 4) {
            for (int i=0; i<m; ++i) ret += roman[d], x -= val[d];
            if (n & 1) ret += roman[d+2], ret += roman[d], x -= val[d], x += val[d+2];
            else ret += roman[d+2], ret += roman[d+1], x -= val[d+1], x += val[d+2];
            string nxt = _r(d+2, abs(x));
            if (x > 0) ret += nxt;
            else ret = nxt + ret;
        } else {
            for (int i=0; i<m; ++i) ret += roman[d], x -= val[d];
            if (n & 1) ret += roman[d+1], x -= val[d+1];
            for (int i=0; i<r; ++i) ret += roman[d+2], x -= val[d+2];
            ret += _r(d+2, x);
        }
		return ret;
    }
    string intToRoman(int num) {
        return _r(0, num);
    }
};
