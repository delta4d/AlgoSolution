// 324ms
// simulation
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = (int)matrix.size(), n = (int)matrix.front().size();
        vector <bool> r(m, false), c(n, false);
        
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
            if (matrix[i][j] == 0) r[i] = true, c[j] = true;
        }
        for (int i=0; i<m; ++i) if (r[i]) {
            for (int j=0; j<n; ++j) matrix[i][j] = 0;
        }
        for (int j=0; j<n; ++j) if (c[j]) {
            for (int i=0; i<m; ++i) matrix[i][j] = 0;
        }
    }
};
