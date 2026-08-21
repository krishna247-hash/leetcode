class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;

        for(auto it : sentences){
            int cnt = 1;
            for(auto x : it){
                if(x == ' ') cnt++;
            }
            maxi = max(maxi , cnt);
        }
        return maxi;
        
    }
};