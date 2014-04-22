// 4ms
// basic math
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <int> ret;
        for (int i=0,x=1; i<=rowIndex; ++i) {
            ret.push_back(x);
            x = (long long)x * (rowIndex - i) / (i + 1);
        }
        return ret;
    }
};
