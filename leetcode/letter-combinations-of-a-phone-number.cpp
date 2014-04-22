// 4ms
// dfs basic
const string ds[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
    char buf[80];
    void dfs(string &d, int dep, const int n, vector <string> &ret) {
        if (dep == n) {
            buf[dep] = '\0';
            ret.push_back(buf);
            return;
        }
        for (auto c: ds[d[dep]-'0']) {
            buf[dep] = c;
            dfs(d, dep+1, n, ret);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector <string> ret;
        int n = (int)digits.length();
        dfs(digits, 0, n, ret);
        return ret;
    }
};
