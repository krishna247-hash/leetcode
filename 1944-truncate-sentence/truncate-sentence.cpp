class Solution {
public:
    string truncateSentence(string s, int k) {
        string temp = "";
        int cnt = 0;
        for(auto it: s){
            

            if(it == ' ') {
                
                cnt++;

            }
            if(cnt == k) return temp;
            temp += it;
            

        }
        return temp;
    }
};