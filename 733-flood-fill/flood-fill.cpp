class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int x = image[sr][sc];
        int y = color;
        if(x == y) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = y;
        while(!q.empty())
        {

            auto it = q.front();
            int r = it.first;
            int c = it.second;
            q.pop();
            for(auto e: dir)
            {
                int r_ = r + e[0];
                int c_ = c + e[1];
                if(r_ >= 0 && r_ < m && c_ < n && c_ >= 0 && image[r_][c_] == x )
                {
                    image[r_][c_] = y;
                    q.push({r_,c_});
                }
            }
        }

        return image;

    }
};