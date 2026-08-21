class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> temp(n+1);
        temp[0] = first; 
        for(int i = 0; i < n; i++){
            temp[i+1] = encoded[i] ^ temp[i];
        }
        return temp;


    }
};