// 48ms
// sim
class Solution {
public:
    int _t(int A[], int a, int b, int step) {
        if (abs(a - b) <= 2) return 0;
        int ret = 0;
        for (int i=a,j; i!=b; ) {
            int sum = 0;
            for (j=i+step; j!=b&&A[j]<A[i]; sum+=A[j],j+=step);
            if (j != b && A[j] >= A[i]) {
                ret += A[i] * (abs(j - i) - 1) - sum;
                i = j;
            } else {
                ret += _t(A, b-step, i-step, -step);
                i = b;
            }
        }
        return ret;
    }
    int trap(int A[], int n) {
        return _t(A, 0, n, 1);
    }
};
