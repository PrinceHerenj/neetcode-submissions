class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int topRow = 0, bottomRow = matrix.size() - 1;
        int width = matrix[0].size() - 1;
        int midRow;

        while (topRow <= bottomRow) {
            midRow = (topRow + bottomRow) / 2;
            if (target < matrix[midRow][0]) bottomRow = midRow - 1;
            else if (target > matrix[midRow][width]) topRow = midRow + 1;
            else if (target >= matrix[midRow][0] && target <= matrix[midRow][width]) break;
        }

        int l = 0, r = width;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (target > matrix[midRow][mid]) l = mid + 1;
            else if (target < matrix[midRow][mid]) r = mid - 1;
            else return true;
        }
        return false; 
    }
};
