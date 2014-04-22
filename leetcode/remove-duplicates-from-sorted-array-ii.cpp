// 88ms
// with extra O(n) space
const int MAXN = 1e5 + 86;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int _A[MAXN], cnt = 1, ret = 0;
        for (int i=1; i<=n; ++i) {
            if (i == n || A[i] != A[i-1]) {
                cnt = min(cnt, 2);
                for (int j=0; j<cnt; ++j) _A[ret++] = A[i-1];
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        for (int i=0; i<ret; ++i) A[i] = _A[i];
        return ret;
    }
};

// 88ms
// without extra space
// consider A as _A
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int ret = 2;
        for (int i=2; i<n; ++i) {
            if (A[i] != A[ret-2]) A[ret++] = A[i];
        }
        return ret;
    }
};
