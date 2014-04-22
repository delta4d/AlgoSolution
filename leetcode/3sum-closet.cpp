// 192ms
// O(n^2logn)
// tow for loop inside runs at most 6 times
const int INF = 0x3f3f3f3f;
int diff[10086];
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = (int)num.size(), mn = INF, ret = -1;
        sort(begin(num), end(num));
        for (int i=0; i<n; ++i) diff[i] = target - num[n-1-i];
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            int x = num[i]+num[j], p = lower_bound(diff, diff+n, x) - diff;
            for (int k=p; 0<=k&&k<n&&diff[k]==diff[p]; ++k) {
                if (i + k + 1 != n && j + k + 1 != n) {
                    int cc = abs(x - diff[k]);
                    if (cc < mn) mn = cc, ret = x - diff[k] + target;
                    break;
                }
            }
            for (int k=p-1; 0<=k&&k<n&&diff[k]==diff[p-1]; --k) {
                if (i + k + 1 != n && j + k + 1 != n) {
                    int cc = abs(x - diff[k]);
                    if (cc < mn) mn = cc, ret = x - diff[k] + target;
                    break;
                }
            }
            if (!mn) return ret;
        }
        return ret;
    }
};
