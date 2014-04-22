// 48ms
class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0, right = n - 1, mid, k = -1;
        while (left <= right) {
            mid = ((left ^ right) >> 1) + (left & right);
            if (A[mid] == target) return true;
			if (A[left] < A[mid]) {
				if (*lower_bound(A+left, A+mid+1, target) == target) return true;
				left = mid + 1;
			} else if (A[left] > A[mid]) {
				if (*lower_bound(A+mid, A+right+1, target) == target) return true;
				right = mid - 1;
			} else {
				++left;
			}
        }
        return false;
    }
};
