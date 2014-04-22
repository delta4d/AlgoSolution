// 8ms
// dp
class Solution {
public:
    string getPermutation(int n, int k) {
        int fac[11] = {1};
        bool v[10] = {false};
        for (int i=1; i<11; ++i) fac[i] = fac[i-1] * i;
        fac[0] = 0;
        string ret;
        for (int i=0; i<n; ++i) {
			int rem = n - i - 1;
            for (int j=n-1; j>=0; --j) if (!v[j]) {
            	if (rem == 0) {
            		ret += char(j + '1');
            		break;
				}
                if (fac[n-i-1] * rem < k && fac[n-i-1] * (rem + 1) >= k) {
                    ret += char(j + '1');
                    k -= fac[n-i-1] * rem;
					v[j] = true;
					break;
                }
				--rem;
            }
        }
        return ret;
    }
};
