// 4ms
// fib
// f(n) = f(n-1) + f(n-2) [O(n)]
// {f(n), f(n-1)} = {{1, 1}, {1, 0}}{f(n-1), f(n-2)} [O(logn)]
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        for (int i=1; i<n; ++i) {
            b += a;
            a = b - a;
        }
        return b;
    }
};
