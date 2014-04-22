// 52ms
// binary search
// with STL
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int a = lower_bound(A, A+n, target) - A;
        int b = upper_bound(A, A+n, target) - A - 1;
        if (A[a] != target) a = b = -1;
        return {a, b};
    }
};

// 28ms
// without STL
class Solution {
public:
	int bsearch(int A[], int n, int target, bool (* lt)(int, int)) {
		int left = 0, right = n - 1, mid, ret = n;
		while (left <= right) {
			mid = left + ((right - left) >> 1);
			if (lt(target, A[mid])) right = mid - 1, ret = mid;
			else left = mid + 1;
		}
		return ret;
	}
    vector<int> searchRange(int A[], int n, int target) {
		int a = bsearch(A, n, target, [](int a, int b){ return a <= b; });
		int b = bsearch(A, n, target, [](int a, int b){ return a < b; }) - 1;
		if (A[a] != target) a = b = -1;
		return {a, b};
    }
};
