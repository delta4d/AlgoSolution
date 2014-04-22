// 60ms
class Solution {
public:
    int jump(int A[], int n) {
        int mx = 0, pmx = 0, ret = 0;
        for (int i=0; i<n; mx=max(mx,i+A[i]),++i) {
            if (i > mx) return -1;
            if (i > pmx) {
                pmx = mx;
                ++ret;
            }
        }
        return ret;
    }
};
