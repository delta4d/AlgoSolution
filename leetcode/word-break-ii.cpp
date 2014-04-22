// 76ms
// same as word-break-i
vector <int> dp[10086];
class Solution {
public:
    void dfs(int cur, string &s, vector <string> &cc, vector <string> &ret) {
        for (auto &pre: dp[cur]) {
            cc.push_back(s.substr(pre+1, cur-pre));
            if (pre == -1) {
                string ss = "";
                for (int i=(int)cc.size()-1; i>0; --i) ss += cc[i] + " ";
                ss += cc.front();
                ret.push_back(ss);
            } else {
                dfs(pre, s, cc, ret);
            }
            cc.pop_back();
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = (int)s.length();
        for (int i=0; i<n; ++i) dp[i].clear();
        for (int i=0; i<n; ++i) {
            if (dict.count(s.substr(0, i+1))) dp[i].push_back(-1);
            for (int j=i; j>0; --j) if (dict.count(s.substr(j, i-j+1)) && !dp[j-1].empty()) {
                dp[i].push_back(j-1);
            }
        }
        vector <string> ret, cc;
        dfs(n-1, s, cc, ret);
        return ret;
    }
};
