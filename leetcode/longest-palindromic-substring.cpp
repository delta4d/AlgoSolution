// 228ms
// O(n^2)
// enumerate the center, then expand
class Solution {
public:
    string longestPalindrome(string s) {
        string ret = "";
        int sz = (int)s.length();
        for (int i=0,j; i<sz; ++i) {
            for (j=0; i-j>=0&&i+j<sz&&s[i-j]==s[i+j]; ++j); --j;
            if (2 * j + 1 > (int)ret.length()) ret = s.substr(i-j, 2*j+1);
            for (j=0; i-j>=0&&i+j+1<sz&&s[i-j]==s[i+j+1]; ++j); --j;
            if (2 * j + 2 > (int)ret.length()) ret = s.substr(i-j, 2*j+2);
        }
        return ret;
    }
};

// 40ms
// O(n)
// Manacher Algorightm
// http://en.wikipedia.org/wiki/Longest_palindromic_substring
class Solution {
public:
    string longestPalindrome(string s) {
        const int MAXN = 1 << 11;
	    int p[MAXN];
		string str = "#";
		for (auto c: s) {
			str += c;
			str += '#';
		}
		int r = 0, mx = 0, st = 0, idx = 0, sz = (int)str.length();
		for (int i=0; i<sz; ++i) {
			if (r > i) p[i] = min(p[2*idx-i], r-i);
			else p[i] = 0;
			for (; i-p[i]>=0&&i+p[i]<sz&&str[i-p[i]]==str[i+p[i]]; ++p[i]);
			--p[i];
			if (p[i] + i > r) {
				r = p[i] + i;
				idx = i;
			}
			if (p[i] > mx) {
				mx = p[i];
				st = i - p[i];
			}
		}
		string buf = str.substr(st, 2*mx+1), ret = "";
		for (auto c: buf) {
			if (c != '#') ret += c;
		}
		return ret;
    }
};
