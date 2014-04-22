// 52ms
// basics
class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = (int)num1.size(), l2 = (int)num2.size();
        vector <int> x(l1 + l2 + 1, 0);
        string ret;
        reverse(begin(num1), end(num1));
        reverse(begin(num2), end(num2));
        for (int i=0; i<l1; ++i) for (int j=0; j<l2; ++j) {
            x[i+j] += (num1[i] - '0') * (num2[j] - '0');
        }
        for (int i=0; i<l1+l2; ++i) {
            x[i+1] += x[i] / 10;
            x[i] %= 10;
        }
        for (; (int)x.size() > 1 && x.back() == 0; x.pop_back());
        for (int i=(int)x.size()-1; i>=0; --i) ret += char(x[i] + '0');
        return ret;
    }
};
