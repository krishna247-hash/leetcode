class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> temp(r,vector<int>(c));
        int m = mat.size();
        int n = mat[0].size();

        if(m * n != r * c)
    return mat;

        int row = 0;  int col = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(col == c) {
                    col = 0;
                    row++;
                }
                temp[row][col++] = mat[i][j];
            }
        }

        return temp;
    }
};