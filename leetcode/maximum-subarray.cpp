// 72ms
// dp
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0, ret = 0, mx = A[0];
        for (int i=0; i<n; ++i) {
            sum += A[i];
            if (sum < 0) sum = 0;
            if (sum > ret) ret = sum;
            if (A[i] > mx) mx = A[i];
        }
        if (mx < 0) ret = mx;
        return ret;
    }
};
