class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> temp;


        for(int i = 0; i < n; i++){
            for(auto it : words[i]){
                if(x == it){
                    temp.push_back(i);
                    break;

                }
            }
        }

        return temp;
    }
};