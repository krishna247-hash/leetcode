class Solution {
public:
    
    bool check(int row, int col, vector<string>& board, int n)
    {
        for(int i = 0; i < n; i++)
        {
            if(board[i][col] == 'Q') return 0;
        }
        for(int i = 0; i < n; i++)
        {
            if(board[row][i] == 'Q') return 0;
        }

       for(int i = row, j = col; i >= 0 && j >= 0; i--,j--)
       {
            if(board[i][j] == 'Q') return 0;
       }

       for(int i = row, j = col; i >= 0 && j < n; i--,j++)
       {
            if(board[i][j] == 'Q') return 0;
       }

       return 1;
    }


    void NQueens(int row, int n, vector<string>& board ,int& ans)
    {
        if(row == n)
        {
            ans++;
            return;
        }

        for(int col = 0; col < n; col++)
        {
            if(check(row,col,board,n))
            {
                board[row][col] = 'Q';
                NQueens(row+1,n,board,ans);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        int ans = 0;
        NQueens(0,n,board,ans);
        return ans;

    }
};