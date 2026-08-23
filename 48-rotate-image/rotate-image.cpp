class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        
        int cols = matrix[0].size();

        vector<vector<int>> temp(rows, vector<int>(cols));

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                temp[i][j] = matrix[rows - 1 - j][i];
            }
        }

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                matrix[i][j] = temp[i][j];
            }
        }

    }
};