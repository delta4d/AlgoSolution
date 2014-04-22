// 52ms
// dfs
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
bool v[100][100];
class Solution {
public:
    bool _e(int x, int y, int d, const int m, const int n, const int len, vector<vector<char> > &board, string &word) {
        if (d == len - 1) return true;
        for (int k=0; k<4; ++k) {
            int tx = x + dx[k], ty = y + dy[k];
            if (tx < 0 || tx >= m || ty < 0 || ty >= n || board[tx][ty] != word[d+1] || v[tx][ty]) continue;
            v[tx][ty] = true;
            if (_e(tx, ty, d+1, m, n, len, board, word)) return true;
            v[tx][ty] = false;
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        int m = (int)board.size(), n = (int)board.front().size(), len = (int)word.length();
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (board[i][j] == word[0]) {
            memset(v, false, sizeof(v));
            v[i][j] = true;
            if (_e(i, j, 0, m, n, len, board, word)) return true;
        }
        return false;
    }
};
