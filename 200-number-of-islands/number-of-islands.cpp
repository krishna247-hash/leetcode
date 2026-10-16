class Solution {
public:
    
    bool check(int i, int j,vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == '0') return false;

        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    cnt++;
                    q.push({i,j});

                    while(!q.empty())
                    {
                        auto it = q.front();
                        q.pop();
                        grid[it.first][it.second] = '0';
                        for(auto e: dir)
                        {
                            int x = it.first + e[0];
                            int y = it.second + e[1];

                            if(check(x,y,grid))
                            {
                                grid[x][y] = '0';
                                q.push({x,y});
                            }
                        }
                    }
                }
            }
        }

        return cnt;
    }
};