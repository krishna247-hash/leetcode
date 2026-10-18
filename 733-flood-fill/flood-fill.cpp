class Solution {
  public:
    
    vector<vector<int>> dir ={{1,0},{-1,0},{0,1},{0,-1}};
    void DFS(int i, int j,int x,vector<vector<int>>& image,int newColor)
    {
        int m = image.size();
        int n = image[0].size();
        image[i][j] = newColor;
        
        for(auto it: dir)
        {
            int i_ = i + it[0];
            int j_ = j + it[1];
            
            if(i_ < m && i_ >= 0 && j_ < n && j_ >= 0 && image[i_][j_] == x)
            {
                DFS(i_,j_,x,image,newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // code here
        
        if(image[sr][sc] == newColor) return image;
        
        DFS(sr,sc,image[sr][sc],image,newColor);
        
        return image;
        
    }
};