// 88ms
// record the max value of suffix array
const int MAXN = 1e5 + 86;
int rmx[MAXN];

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0, n = (int)prices.size();
        reverse(begin(prices), end(prices));
        partial_sum(begin(prices), end(prices), rmx, [](int a, int b) {
            return a < b ? b : a;
        });
        for (int i=n-1; i>=0; --i) ret = max(ret, rmx[i]-prices[i]);
        return ret;
    }
};
