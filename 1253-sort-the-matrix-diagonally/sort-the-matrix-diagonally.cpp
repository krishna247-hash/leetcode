class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++)
        {
            vector<int>temp;

            int row = i; int col = 0;
            while(row < m && col < n)
            {
                temp.push_back(mat[row++][col++]);
            }

            row = i; col = 0;
            int t = 0;
            sort(temp.begin(),temp.end());
            while(row < m && col < n)
            {
                mat[row++][col++] = temp[t++];
            }
        }

        for(int j = 1; j < n; j++)
        {
             vector<int>temp;
             int col = j;  int row = 0;
             while(col < n && row < m)
             {
                temp.push_back(mat[row++][col++]);
             }
             sort(temp.begin(),temp.end());
              col = j;   row = 0;
               int t = 0;
              while(row < m && col < n)
            {
                mat[row++][col++] = temp[t++];
            }
        }
        return mat;
    }
};