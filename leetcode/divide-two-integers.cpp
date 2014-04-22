// 88ms
// bits
#define SGN(x) ((x) < 0 ? -1 : 1)
#define ABS(x) ((long long)(x) * SGN(x))
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ret = 0, sgn = SGN(dividend) * SGN(divisor);
        long long x = ABS(dividend), y = ABS(divisor);
        for (long long i=32,rem=0; i>=0; --i) {
            rem = (rem << 1) ^ !!(x & 1ll << i);
            ret <<= 1;
            if (rem >= y) {
                rem -= y;
                ret ^= 1;
            }
        }
        return int(ret * sgn);
    }
};
