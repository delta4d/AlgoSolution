// 36ms
// addition
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector <int> ret;
        int n = (int)digits.size();
        ++digits.back();
        for (int i=n-1; digits[i]>=10&&i>0; --i) {
            digits[i-1] += digits[i] / 10;
            digits[i] %= 10;
        }
        if (digits.front() >= 10) {
            ret.push_back(digits.front() / 10);
            digits.front() %= 10;
        }
        ret.insert(end(ret), begin(digits), end(digits));
        return ret;
    }
};
