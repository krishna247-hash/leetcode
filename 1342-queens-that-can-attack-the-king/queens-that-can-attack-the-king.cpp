class Solution {
public:
    
    void solve(vector<string>& board,int row, int col,vector<vector<int>>& ans)
    {

        if(row > 0)
        {
            for(int i = row; i >= 0; i--)
            {
                if(board[i][col] == 'Q')
                {
                    ans.push_back({i,col});
                    break;
                }
            }
        }
        if(col > 0)
        {
            for(int i = col; i >= 0; i--)
            {
                if(board[row][i] == 'Q')
                {
                    ans.push_back({row,i});
                    break;
                }
            }
        }
        if(row < 7)
        {
            for(int i = row; i <= 7; i++)
            {
                if(board[i][col] == 'Q')
                {
                    ans.push_back({i,col});
                    break;
                }
            }
        }
        if(col < 7)
        {
            for(int i = col; i <= 7; i++)
            {
                if(board[row][i] == 'Q')
                {
                    ans.push_back({row,i});
                    break;
                }
            }
        }

        int i = row; int j = col;

        while(i >=0 && j >= 0 && j < 8 && i < 8)
        {
            if(board[i][j] == 'Q')
            {
                    ans.push_back({i,j});
                    break;
            } 
            i--;
            j--;  
        }

        i = row; j = col;
        while(i >=0 && j >= 0 && j < 8 && i < 8)
        {
            if(board[i][j] == 'Q')
            {
                    ans.push_back({i,j});
                    break;
            } 
            i--;
            j++;  
        }

         i = row; j = col;
        while(i >=0 && j >= 0 && j < 8 && i < 8)
        {
            if(board[i][j] == 'Q')
            {
                    ans.push_back({i,j});
                    break;
            } 
            i++;
            j--;  
        }

        i = row; j = col;
        while(i >=0 && j >= 0 && j < 8 && i < 8)
        {
            if(board[i][j] == 'Q')
            {
                    ans.push_back({i,j});
                    break;
            } 
            i++;
            j++;  
        }


    }

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<string> board(8,string(8,'.'));
        for(auto it: queens)
        {
            board[it[0]][it[1]] = 'Q';
        }
        board[king[0]][king[1]] = 'K';
        vector<vector<int>> ans;

        solve(board,king[0],king[1],ans);

        return ans;
    }
};