// 40ms
// simulation
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        int n = (int)strs.size(), len = (int)strs.front().length();
        for (int i=0; i<len; ++i) {
            for (int j=1; j<n; ++j) {
                if ((int)strs[j].length() < i + 1) return strs[0].substr(0, i);
                if (strs[j][i] != strs[0][i]) return strs[0].substr(0, i);
            }
        }
        return strs.front();
    }
};
