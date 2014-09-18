// 36ms
// move A[.] to A[.+n]
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for (int i=m+n-1; i>=n; --i) A[i] = A[i-n];
        int pa = n, pb = 0, p = 0;
        while (pa < m + n && pb < n) {
            if (A[pa] < B[pb]) A[p++] = A[pa++];
            else A[p++] = B[pb++];
        }
        for (; pa<m+n; A[p++]=A[pa++]);
        for (; pb<n; A[p++]=B[pb++]);
    }
};

// merge backwards to avoid copy A[.] to A[.+n]
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for (int k=m+n-1,i=m-1,j=n-1; j>=0; ) {
            if (i == -1) A[k--] = B[j--];
            else if (A[i] < B[j]) A[k--] = B[j--];
            else A[k--] = A[i--];
        }
    }
};
