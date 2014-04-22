// 16ms
// O(logn)
// binary
// x^n = x^{n/2} * x^{n/2}		n is even
//     = x^{n/2} * x^{n/2} * x	n is odd
class Solution {
public:
    double pow(double x, int n) {
        int sgn = n < 0 ? -1 : 1;
        long long e = (long long)n * sgn;
        double ret = 1;
        for (; e; e>>=1,x=x*x) if (e & 1) ret = ret * x;
        if (sgn == -1) ret = 1 / ret;
        return ret;
    }
};
