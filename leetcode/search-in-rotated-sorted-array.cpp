// 56ms
// binary search
class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0, right = n - 1, mid, k = -1;
        while (left <= right) {
            mid = ((left ^ right) >> 1) + (left & right);
            if (A[mid] > A[n-1]) left = mid + 1;
            else right = mid - 1, k = mid;
        }
        if (k == -1) throw "error!";
        int ret = lower_bound(A, A+k, target) - A;
        if (A[ret] == target) return ret;
        ret = lower_bound(A+k, A+n, target) - A;
        if (A[ret] == target) return ret;
        return -1;
    }
};
