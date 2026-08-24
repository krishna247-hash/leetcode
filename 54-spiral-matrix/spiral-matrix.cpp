class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> temp;

        int top = 0;
        int left = 0;
        int bottom = rows - 1;
        int right = cols - 1;

        while (top <= bottom && left <= right) {

            // Left -> Right
            for (int i = left; i <= right; i++) {
                temp.push_back(matrix[top][i]);
            }
            top++;

            // Top -> Bottom
            for (int i = top; i <= bottom; i++) {
                temp.push_back(matrix[i][right]);
            }
            right--;

            // Right -> Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    temp.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    temp.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return temp;
    }
};