class Solution {
public:
    int countPos(vector<vector<int>>& matrix, int x)
    {
        int n = matrix.size();
        int cnt = 0;
        int col = n - 1; int row = 0;
        while(col >= 0 && row < n)
        {
            if(matrix[row][col] <= x)
            {
                cnt += (col + 1);
                row++;
            }
            else
            {
                col--;
            }
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int ans = -1;
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        while(high >= low)
        {
            int mid = low + (high - low)/2;
            int count = countPos(matrix,mid);

            if(count < k)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;

        
    }
};