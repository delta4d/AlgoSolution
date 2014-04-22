// 40ms
// basic dp
// no need for extra space
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = (int)triangle.size();
        for (int i=n-2; i>=0; --i) for (int j=0; j<=i; ++j) {
            triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        }
        return triangle.front().front();
    }
};
