// 52ms
// basic binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = (int)matrix.size(), n = (int)matrix.front().size();
        int left = 0, right = m * n - 1, mid, ret = m * n;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (matrix[mid/n][mid%n] <= target) left = mid + 1, ret = mid;
            else right = mid - 1;
        }
        return 0 <= ret && ret < m * n && matrix[ret/n][ret%n] == target;
    }
};
