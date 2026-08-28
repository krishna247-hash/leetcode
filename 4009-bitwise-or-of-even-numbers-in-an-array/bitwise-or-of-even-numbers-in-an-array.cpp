class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int OR = 0;

        for(auto it : nums){
            if(it % 2 == 0) {
                OR |= it;
            }
            
        }

        return OR;
    }
};