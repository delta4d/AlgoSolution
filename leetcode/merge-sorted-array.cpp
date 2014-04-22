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
