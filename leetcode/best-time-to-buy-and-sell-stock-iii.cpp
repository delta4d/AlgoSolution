// 56ms
// dp
typedef int (* F)(int, int);
int fmx(int a, int b) { return a > b ? a : b; }
int fmn(int a, int b) { return a < b ? a : b; }

class Solution {
public:
    void _m(vector <int> &x, vector <int> &ret, int a, int b, int step, F f) {
        vector <int> mx(abs(b-a)+1);
        ret.resize(abs(b-a)+1);
        mx[b] = x[b];
        for (int i=b-step; i!=a-step; i-=step) mx[i] = f(mx[i+step], x[i]);
        for (int i=a; i!=b; i+=step) ret[i] = mx[i+step] - x[i];
        ret[b] = 0;
        for (int i=b-step; i!=a-step; i-=step) ret[i] = f(ret[i], ret[i+step]);
    }
    int maxProfit(vector<int> &prices) {
        int n = (int)prices.size();
        if (n < 2) return 0;
        vector <int> L, R;
        _m(prices, R, 0, n-1, 1, fmx);
        _m(prices, L, n-1, 0, -1, fmn);
        int ret = R[0];
        for (int i=0; i+1<n; ++i) ret = max(ret, R[i+1]-L[i]);
        return ret;
    }
};

// 28ms
// a short ver
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = (int)prices.size();
        if (n == 0) return 0;
        vector <int> suf(n), pre(n);
        int mn = prices.front(), mx = prices.back();
        for (int i=1; i<n; ++i) pre[i] = max(pre[i-1], prices[i] - mn), mn = min(mn, prices[i]);
        for (int i=n-2; i>=0; --i) suf[i] = max(suf[i+1], mx - prices[i]), mx = max(mx, prices[i]);
        int ret = suf.front();
        for (int i=0; i+1<n; ++i) {
            ret = max(ret, pre[i]+suf[i+1]);
        }
        return ret;
    }
};
