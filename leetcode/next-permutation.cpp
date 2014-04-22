// 60ms
// simulation
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = (int)num.size();
        for (int i=n-1; i>=0; --i) {
            for (int j=n-1; j>i; --j) if (num[j] > num[i]) {
                swap(num[i], num[j]);
                sort(begin(num)+i+1, end(num));
                return;
            }
        }
        reverse(begin(num), end(num));
    }
};

// 56ms
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = (int)num.size();
        for (int i=n-1; i>0; --i) if (num[i] > num[i-1]) {
            for (int j=n-1; j>=i; --j) if (num[j] > num[i-1]) {
                swap(num[j], num[i-1]);
                reverse(begin(num)+i, end(num));
                return;
            }
        }
        reverse(begin(num), end(num));
    }
};
