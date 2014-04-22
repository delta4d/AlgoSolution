// 64ms
// same as largest-rectangle-in-histogram
// O(n^2)
int r[1000][1000];
int L[1000], R[1000];
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) return 0;
        int m = (int)matrix.size(), n = (int)matrix.front().size();
        for (int i=0; i<m; ++i) {
            r[i][n] = -1;
            for (int j=n-1; j>=0; --j) {
                if (matrix[i][j] == '0') r[i][j] = -1;
                else r[i][j] = r[i][j+1] == -1 ? j : r[i][j+1];
            }
        }
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
            r[i][j] = r[i][j] == -1 ? 0 : r[i][j] - j + 1;
        }
        int ret = 0;
        for (int j=0; j<n; ++j) {
            int cc = 0;
            L[0] = -1;
            for (int i=1,k; i<m; ++i) {
                for (k=i-1; k>=0&&r[k][j]>=r[i][j]; k=L[k]);
                L[i] = k;
            }
            R[m-1] = m;
            for (int i=m-2,k; i>=0; --i) {
                for (k=i+1; k<m&&r[k][j]>=r[i][j]; k=R[k]);
                R[i] = k;
            }
            for (int i=0; i<m; ++i) {
                int cmx = max(R[i] - L[i] - 1, 0) * r[i][j];
                cc = max(cc, cmx);
            }
            ret = max(ret, cc);
        }
        return ret;
    }
};
