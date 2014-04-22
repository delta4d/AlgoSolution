// 36ms
// f(n) = \sum_{i=0}^{n-1}f(i)f(n-1-i)
//      = \frac{\binom{2n}{n}}{n+1}
// Catalan Number
class Solution {
public:
    int numTrees(int n) {
        long long ret = 1;
        for (int i=0; i<n; ++i) ret = ret * (2 * n - i) / (i + 1);
        ret /= n + 1;
        return (int)ret;
    }
};
