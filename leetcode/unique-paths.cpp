// 4ms
// basic math, \binom{m+n-2}{m-1}
class Solution {
public:
    int uniquePaths(int m, int n) {
        --m, --n;
        long long ret = 1;
        for (int i=0,k=min(m,n); i<k; ++i) {
            ret = ret * (m + n - i) / (i + 1);
        }
        return int(ret);
    }
};
