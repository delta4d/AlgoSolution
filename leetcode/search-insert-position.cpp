// 20ms
// binary search
// with STL
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        return lower_bound(A, A+n, target) - A;
    }
};

// 40ms
// without STL
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0, right = n - 1, mid, ret = n;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (A[mid] >= target) right = mid - 1, ret = mid;
            else left = mid + 1;
        }
        return ret;
    }
};
