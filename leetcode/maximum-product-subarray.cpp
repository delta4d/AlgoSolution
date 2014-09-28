// 40ms
// record max and min
class Solution {
public:
    int maxProduct(int A[], int n) {
        int mn = 1, mx = 1, ret = A[0];
        for (int i=0; i<n; ++i) {
            int _mn = min({mx*A[i], mn*A[i], A[i]}), _mx = max({mx*A[i], mn*A[i], A[i]});
            mn = _mn, mx = _mx;
            ret = max(ret, mx);
        }
        return ret;
    }
};
