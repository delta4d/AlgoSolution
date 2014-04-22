// 268ms
// simulation
const char roman[] = "CDILMVX";
const int d[] = {100, 500, 1, 50, 1000, 5, 10};
class Solution {
public:
    int _R(const char x) {
        return d[lower_bound(roman, roman+7, x) - roman];
    }
    int romanToInt(string s) {
        int ret = 0, n = (int)s.length();
		int mx = 0;
		for (int i=n-1; i>=0; --i) {
			int v =  _R(s[i]);
			if (i == n - 1 || mx <= v) ret += v;
			else ret -= v;
			mx = max(mx, v);
		}
		return ret;
    }
};
