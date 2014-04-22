// 36ms
// simulate
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = (int)matrix.size();
        for (int i=0; i+i<n; ++i) for (int j=i; j+i+1<n; ++j) {
            swap(matrix[i][j], matrix[j][n-1-i]);
            swap(matrix[n-1-i][n-1-j], matrix[n-1-j][i]);
            swap(matrix[i][j], matrix[n-1-i][n-1-j]);
        }
    }
};
