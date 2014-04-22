// 8ms
// dfs
bool col[9][9], row[9][9], sqr[9][9], find_one;
vector <pair<int,int>> tobe;
class Solution {
public:
    void dfs(int d, int const n, vector<vector<char>> &ret) {
        if (find_one) return;
        if (d == n) {
            find_one = true;
            return;
        }
        int x = tobe[d].first, y = tobe[d].second, z = x / 3 * 3 + y / 3;
        for (int k=0; k<9; ++k) if (!col[y][k] && !row[x][k] && !sqr[z][k]) {
            ret[x][y] = k + '1';
            col[y][k] = true, row[x][k] = true, sqr[z][k] = true;
            dfs(d+1, n, ret);
            if (find_one) return;
            col[y][k] = false, row[x][k] = false, sqr[z][k] = false;
        }
    }
    void solveSudoku(vector<vector<char> > &board) {
        find_one = false;
        memset(col, false, sizeof(col));
        memset(row, false, sizeof(row));
        memset(sqr, false, sizeof(sqr));
        tobe.clear();
        for (int i=0; i<9; ++i) for (int j=0; j<9; ++j) {
            int k = board[i][j] - '1';
            if (board[i][j] == '.') tobe.push_back(make_pair(i, j));
            else col[j][k] = true, row[i][k] = true, sqr[i/3*3+j/3][k] = true;
        }
        dfs(0, (int)tobe.size(), board);
    }
};
