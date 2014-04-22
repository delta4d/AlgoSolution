// 40ms
// basics
class Solution {
public:
    int reverse(int x) {
        int sgn = x < 0 ? -1 : 1, rev = 0;
        x *= sgn;
        for (; x; rev=rev*10+x%10,x/=10);
        rev *= sgn;
        return rev;
    }
};
