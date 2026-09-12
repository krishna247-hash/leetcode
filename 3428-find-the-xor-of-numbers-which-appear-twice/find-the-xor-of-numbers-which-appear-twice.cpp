class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0; int j = 1;
        int XOR = 0;
        while(j < nums.size())
        {
            if(nums[i] == nums[j])
            {
                XOR ^= nums[i];
                i = j+1;
                j = i+1;
            }
            else
            {
                i = j;
                j++;
            }
        }
        return XOR;
    }
};