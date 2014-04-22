// 252ms
// O(log(m)log(n))
// binary search on both A and B
class Solution {
public:
    int _kth(int A[], int m, int B[], int n, int k) {
        int left(0), right(min(m-1,k)), mid;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            int pos = lower_bound(B, B+n, A[mid]) - B + mid;
			int up = upper_bound(B, B+n, A[mid]) - B - 1;
			if (B[up] != A[mid]) up = pos;
			else up += mid + 1;
            if (pos <= k && k <= up) return A[mid];
            if (pos < k) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    int kth(int A[], int m, int B[], int n, int k) {
        int ret = _kth(A, m, B, n, k);
        if (ret == -1) ret = _kth(B, n, A, m, k);
        return ret;
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int sz = m + n;
        if (sz & 1) return kth(A, m, B, n, sz>>1);
        return (kth(A, m, B, n, sz>>1) + kth(A, m, B, n, (sz-1)>>1)) / 2.0;
    }
};

// 204ms
// O(log(m+n))
// compare A[i] and B[k-i], the small one cannot be the kth number
class Solution {
public:
    int kth(int A[], int m, int B[], int n, int k) {
        if (n == 0) return A[k];
        if (m == 0) return B[k];
        if (k == 0) return min(A[0], B[0]);
        int pa = min(m-1, k/2), pb = k - pa - 1;
        if (pb < 0 || pb >= n) pb = min(n-1, k/2), pa = k - pb - 1;
        int a = A[pa], b = B[pb];
        if (a == b) return a;
        if (a < b) return kth(A+pa+1, m-pa-1, B, n, k-pa-1);
        return kth(A, m, B+pb+1, n-pb-1, k-pb-1);
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int sz = m + n;
        if (sz & 1) return kth(A, m, B, n, sz>>1);
        return (kth(A, m, B, n, sz>>1) + kth(A, m, B, n, (sz-1)>>1)) / 2.0;
    }
};
