class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        int maxi = n * n;
         vector<vector<int>> matrix(n,vector<int>(n));

        int top = 0;       int left = 0;
        int bottom = n-1;  int right = n - 1;

        int j = 1;

        while(top <= bottom && left <= right)
        {
            for(int i = left; i<= right; i++)
            {
                matrix[top][i] = j++;
            }
            top++;
            for(int i = top; i <= bottom; i++)
            {
                matrix[i][right] = j++;
            }
            right--;
            for(int i = right; i>= left; i--)
            {
                matrix[bottom][i] = j++;
            }
            bottom--;
            for(int i = bottom; i>= top; i--)
            {
                matrix[i][left] = j++;
            }
            left++;
        }
        return matrix;
  
    }
};