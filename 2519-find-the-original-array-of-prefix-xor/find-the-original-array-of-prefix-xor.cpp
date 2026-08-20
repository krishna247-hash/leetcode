class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> temp(n);
        temp[0] = pref[0];
        for(int i = 1; i < n; i++){
            temp[i] = pref[i-1]^pref[i];
        }
        return temp;


    }
};