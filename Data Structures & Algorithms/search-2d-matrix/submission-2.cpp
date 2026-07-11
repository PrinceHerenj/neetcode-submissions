class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        int l = 0, r = rows * cols - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int row = mid / cols, col = mid % cols;
            if (target > matrix[row][col]) l = mid + 1;
            else if (target < matrix[row][col]) r = mid - 1;
            else return true;
        }
        return false;

        
    }
};
