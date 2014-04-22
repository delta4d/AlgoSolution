// 64ms
// dfs
const int dx[] = {1, 1, 1};
const int dy[] = {-1, 0, 1};
bool v[32][32];
string s = ".................................";
class Solution {
public:
    void _s(int d, int n, vector <string> &cc, vector <vector <string>> &ret) {
        if (d == n) {
            ret.push_back(cc);
            return;
        }
        for (int i=0; i<n; ++i) if (!v[d][i]) {
            cc[d][i] = 'Q';
            vector <pair <int, int>> mark;
            for (int k=0; k<8; ++k) {
                for (int x=d,y=i; 0<=x&&x<n&&0<=y&&y<n; x+=dx[k],y+=dy[k]) if (!v[x][y]) {
                    mark.push_back(make_pair(x, y));
                    v[x][y] = true;
                }
            }
            _s(d+1, n, cc, ret);
            for (auto &p: mark) v[p.first][p.second] = false;
            cc[d][i] = '.';
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector <string> cc(n);
        vector <vector <string>> ret;
        memset(v, false, sizeof(v));
        cc.front() = s.substr(0, n);
        for (int i=1; i<n; ++i) cc[i] = cc.front();
        _s(0, n, cc, ret);
        return ret;
    }
};
