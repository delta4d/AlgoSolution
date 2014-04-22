// 8ms
// traversal
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector <vector<int>> ret;
        ret.resize(n);
        for (int i=0; i<n; ++i) ret[i].resize(n, -1);
        for (int i=0,x=0,y=0,d=0; i<n*n; ++i) {
            ret[x][y] = i + 1;
            int tx = x + dx[d], ty = y + dy[d];
            if (tx < 0 || tx >= n || ty < 0 || ty >= n || ret[tx][ty] != -1) {
                d = (d + 1) & 3;
                tx = x + dx[d], ty = y + dy[d];
            }
            x = tx, y = ty;
        }
        return ret;
    }
};
