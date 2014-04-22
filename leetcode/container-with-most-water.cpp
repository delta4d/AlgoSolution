// 212ms
// record the prefix max, and binary search [O(nlogn)]
#define all(x) begin(x), end(x)
const int MAXN = 1e5 + 86;

class Solution {
public:
    int lmx[MAXN];
    int _maxArea(vector <int> &h, const int n) {
        int mx = 0;
        partial_sum(all(h), lmx, [](int a, int b) {
            return a < b ? b : a;
        });
        for (int i=1; i<n; ++i) {
            int j = lower_bound(lmx, lmx+i, h[i]) - lmx;
            if (0 <= j && j < i) mx = max(mx, (i - j) * h[i]);
        }
        return mx;
    }
    int maxArea(vector<int> &height) {
        int ret = 0, n = (int)height.size();
        if (n == 0) return ret;
        ret = max(ret, _maxArea(height, n));
        reverse(all(height));
        ret = max(ret, _maxArea(height, n));
        return ret;
    }
};

// 80ms
// two-pointers [O(n)]
class Solution {
public:
    int maxArea(vector<int> &height) {
        int ret = 0, n = (int)height.size();
        for (int i=0,j=n-1; i<=j; height[i]<height[j]?++i:--j) {
            ret = max(ret, (j - i) * min(height[i], height[j]));
        }
        return ret;
    }
};
