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

// 88ms
// bit mask
using ull = unsigned long long;
class Solution {
public:
    int singleNumber(int A[], int n) {
        ull state = 0;
        for (int i=0; i<n; ++i) {
            for (int x=A[i]; x; x&=x-1) {
				ull mask = x - (x & (x - 1));
				mask *= mask;
				ull bit_state = (state / mask) & 3;
				bit_state = (bit_state + 1) % 3;
				state &= ~(mask | (mask << 1));
				state ^= bit_state * mask;
            }
        }
        int ret = 0;
        for (ull i=0; i<32; ++i) {
            ret ^= ((state >> (i << 1)) & 1) << i;
        }
        return ret;
    }
};
