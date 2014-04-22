// 8ms
// answer lies in [1, n+1]
// using A as hash, A[i] indicates if i + 1 exists
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i=0,j,k; i<n; ++i) for (k=A[i]; 0<k&&k<=n&&A[k-1]!=k; j=A[k-1],A[k-1]=k,k=j);
        for (int i=0; i<n; ++i) if (A[i] != i + 1) return i + 1;
        return n + 1;
    }
};
