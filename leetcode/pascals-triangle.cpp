// 4ms
// basics
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector <vector <int>> ret;
        for (int i=0; i<numRows; ++i) {
            vector <int> c(i+1);
            for (int j=1; j<i; ++j) {
                c[j] = ret.back()[j-1] + ret.back()[j];
            }
            c.front() = c.back() = 1;
            ret.push_back(c);
        }
        return ret;
    }
};
