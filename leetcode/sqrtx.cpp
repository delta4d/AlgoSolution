// 76ms
// basic binary search
class Solution {
public:
    int sqrt(int x) {
        int left = 0, right = x, mid, ret = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if ((long long)mid * mid <= x) left = mid + 1, ret = mid;
            else right = mid - 1;
        }
        return ret;
    }
};

// 64ms
// http://en.wikipedia.org/wiki/Methods_of_computing_square_roots
class Solution {
public:
    int sqrt(int x) {
        int bit = 1 << 30, ret = 0;
        for (; bit>x; bit>>=2);
        for (; bit; bit>>=2) {
            if (x >= ret + bit) {
                x -= ret + bit;
                ret = (ret >> 1) + bit;
            } else {
                ret >>= 1;
            }
        }
        return ret;
    }
};
