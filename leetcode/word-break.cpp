// 4ms
// dp
bool dp[10086];
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = (int)s.length();
        memset(dp, false, n*sizeof(bool));
        for (int i=0; i<n; ++i) {
            if (dict.count(s.substr(0, i+1))) {
                dp[i] = true;
                continue;
            }
            for (int j=i; j>0; --j) if (dict.count(s.substr(j,i-j+1)) && dp[j-1]) {
                dp[i] = true;
                break;
            }
        }
        return dp[n-1];
    }
};
