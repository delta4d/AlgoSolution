// 88ms
// hash
class Solution {
public:
    int singleNumber(int A[], int n) {
        unordered_map <int, int> cnt;
        int ret = 0;
        for (int i=0; i<n; ++i) ret ^= (++cnt[A[i]] < 3) * A[i];
        return ret;
    }
};

// 28ms
// bits
class Solution {
public:
    int singleNumber(int A[], int n) {
        int c[32] = {0}, ret = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<32; ++j) {
                c[j] += !!(A[i] & 1 << j);
            }
        }
        for (int j=0; j<32; ++j) ret |= (c[j] % 3) << j;
        return ret;
    }
};
