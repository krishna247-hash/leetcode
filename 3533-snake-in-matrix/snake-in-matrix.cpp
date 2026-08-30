class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
       
       int col = 0;  int row = 0;
       for(auto it: commands)
       {
        if(it == "UP") row--;
        else if(it == "RIGHT") col++;
        else if(it == "DOWN") row++;
        else col--;
       }
        
        return (n * row + col);
    }
};