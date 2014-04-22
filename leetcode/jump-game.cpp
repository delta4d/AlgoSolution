// 44ms
// simulation
class Solution {
public:
    bool canJump(int A[], int n) {
        int p;
        for (p=A[0]; A[p]&&p+1<n; p+=A[p]);
        return p + 1 >= n;
    }
};
