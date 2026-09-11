class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int row = 0; row < n; row++)
        {
            vector<int> mp(n,0);
            for(int col = 0; col < n; col++)
            {
                mp[matrix[row][col]-1] = 1;
            }

            for(int i = 0; i < n; i++)
            {
                if(mp[i] == 0) return false;
            }
        }

         for(int col = 0; col < n; col++)
        {
            vector<int> mp(n,0);
            for(int row = 0; row < n; row++)
            {
                mp[matrix[row][col]-1] = 1;
            }

            for(int i = 0; i < n; i++)
            {
                if(mp[i] == 0) return false;
            }
        }

        return true;
    }
};