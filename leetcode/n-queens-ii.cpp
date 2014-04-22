// 56ms
// same as n-queens-i
const int dx[] = {1, 1, 1};
const int dy[] = {-1, 0, 1};
bool v[32][32];
class Solution {
public:
    void _s(int d, int n, int &tot) {
        if (d == n) {
            ++tot;
            return;
        }
        for (int i=0; i<n; ++i) if (!v[d][i]) {
            vector <pair <int, int>> mark;
            for (int k=0; k<8; ++k) {
                for (int x=d,y=i; 0<=x&&x<n&&0<=y&&y<n; x+=dx[k],y+=dy[k]) if (!v[x][y]) {
                    mark.push_back(make_pair(x, y));
                    v[x][y] = true;
                }
            }
            _s(d+1, n, tot);
            for (auto &p: mark) v[p.first][p.second] = false;
        }
    }
    int totalNQueens(int n) {
        int ret = 0;
        _s(0, n, ret);
        return ret;
    }
};
