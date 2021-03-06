// 104ms
// note the length of expected string is no more than 26
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0, len = (int)s.length();
        for (int i=0,j; i<len; ++i) {
            bool v[26] = {false};
            for (j=0; i+j<len&&j<26; ++j) {
                int c = s[i+j] - 'a';
                if (v[c]) break;
                v[c] = true;
            }
            ret = max(ret, j);
        }
        return ret;
    }
};

// 80ms
// move a window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0, len = (int)s.length();
		bool v[26] = {false};
		for (int i=0,j=0; i<len; ++i) {
			for (; j<len; ++j) {
				int c = s[j] - 'a';
				if (v[c]) {
					for (; s[i]-'a'!=c; ++i) v[s[i]-'a'] = false;
				} else {
					v[c] = true;
				}
			}
			ret = max(ret, j-i+1);
		}
        return ret;
    }
};

// shorter ver
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256], ret = 0, n = (int)s.length();
        memset(last, -1, sizeof(last));
        for (int i=0,st=0; i<n; ++i) {
            st = max(st, last[s[i]]+1);
            last[s[i]] = i;
            ret = max(ret, i-st+1);
        }
        return ret;
    }
};
