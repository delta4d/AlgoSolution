// 52ms
// dp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = (int)prices.size();
        vector <int> f(n+1, 0);
        
        for (int i=n-1,mx=0; i>=0; --i) {
            f[i] = max(f[i+1], mx-prices[i]);
            mx = max(mx, prices[i]+f[i+1]);
        }
        return *max_element(begin(f), end(f));
    }
};
