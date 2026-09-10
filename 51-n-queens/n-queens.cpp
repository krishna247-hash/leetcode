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

        int i = row, j = col;
        while(i >= 0 && j >= 0)
        {
            if(board[i][j] == 'Q') return 0;
            i--;
            j--;
        }

        i = row; j = col;

        while(i >= 0 && j < n)
        {
            if(board[i][j] == 'Q') return 0;
            i--;
            j++;
        }

        return true;
    }
    
    void Nqueens(int row, int n, vector<vector<string>>& ans, vector<string>& board)
    {

       if(row == n)
       {
           ans.push_back(board);
           return;
       }


        for(int col = 0; col < n; col++)
        {
            if(check(row,col,board,n))
            {
                board[row][col] = 'Q';
                Nqueens(row + 1, n, ans, board);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n ,string(n,'.'));
        Nqueens(0,n,ans,board);
        return ans;
        
    }
};