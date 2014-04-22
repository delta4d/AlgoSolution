// 44ms
// basic dp
#define valid(x, y) ((x) >= 0 && (y) >= 0 && !obstacleGrid[(x)][(y)])
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = (int)obstacleGrid.size(), n = (int)obstacleGrid.front().size();
        int f[101][101]={0};
        f[0][0] = 1 - obstacleGrid[0][0];
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if ((i + j) && !obstacleGrid[i][j]) {
            f[i][j] = valid(i-1, j) * f[i-1][j] + valid(i, j-1) * f[i][j-1];
        }
        return f[m-1][n-1];
    }
};
