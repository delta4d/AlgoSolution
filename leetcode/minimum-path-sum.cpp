// 56ms
// basic dp
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty()) return 0;
        int m = (int)grid.size(), n = (int)grid.front().size();
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
            if (i == 0 && j != 0) grid[i][j] += grid[i][j-1];
            else if (i != 0 && j == 0) grid[i][j] += grid[i-1][j];
            else if (i != 0 && j != 0) grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
        return grid[m-1][n-1];
    }
};
