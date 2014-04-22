// 144ms
// with STL
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        return unique(A, A+n) - A;
    }
};

// 164ms
// without STL
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) return n;
        int ret = 1;
        for (int i=1; i<n; ++i) {
            if (A[i] != A[ret-1]) A[ret++] = A[i];
        }
        return ret;
    }
};
