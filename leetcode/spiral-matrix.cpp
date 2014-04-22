// 28ms
// simulation
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int DIRTY = 0x3f3f3f3f;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if (matrix.empty()) return {};
        int m = (int)matrix.size(), n = (int)matrix.front().size();
        vector <int> ret;
        for (int x=0,y=0,k=0,c=m*n; c--; x+=dx[k],y+=dy[k]) {
            ret.push_back(matrix[x][y]);
            matrix[x][y] = DIRTY;
            int tx = x + dx[k], ty = y + dy[k];
            if (tx < 0 || tx >= m || ty < 0 || ty >= n || matrix[tx][ty] == DIRTY) k = (k + 1) & 3;
        }
        return ret;
    }
};
