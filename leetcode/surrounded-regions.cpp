// 96ms
// bfs basic (floodfill)
const int MAXN = 1 << 10;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool v[MAXN][MAXN];
class Solution {
public:
    bool bfs(int sx, int sy, const int m, const int n, vector <int> &region, const vector<vector<char>> &board) {
        bool ret = true;
        queue <int> q;
        
        region.clear();
        region.push_back(sx*n+sy);
        q.push(sx*n+sy);
        v[sx][sy] = true;
        while (!q.empty()) {
            sx = q.front() / n, sy = q.front() % n;
            q.pop();
            for (int k=0; k<4; ++k) {
                int tx = sx + dx[k], ty = sy + dy[k];
                if (tx < 0 || tx >= m || ty < 0 || ty >= n) {
                    ret = false;
                    continue;
                }
                if (v[tx][ty] || board[tx][ty] == 'X') continue;
                v[tx][ty] = true;
                region.push_back(tx*n+ty);
                q.push(tx*n+ty);
            }
        }
        return ret;
    }
    void solve(vector<vector<char>> &board) {
        if (board.empty()) return;
        int m = (int)board.size(), n = (int)board.front().size();
        vector <int> region;
        memset(v, false, sizeof(v));
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (board[i][j] == 'O' && !v[i][j]) {
            if (bfs(i, j, m, n, region, board)) {
                for (auto k: region) board[k/n][k%n] = 'X';
            }
        }
    }
};
