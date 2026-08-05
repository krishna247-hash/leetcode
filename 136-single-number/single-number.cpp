class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR = 0;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            XOR = XOR ^ nums[i];
        } 
        return XOR;
        
    }



    //   int singleNumber(vector<int>& nums) {
        
    //    int n = nums.size();

    //    unordered_map<int,int>mp;
    //    for(int i = 0; i < n; i++){
    //     mp[nums[i]]++;

    //    }
    //     for(int i = 0; i < n; i++){
    //     if (mp[nums[i]]== 1)
    //     {
    //         return nums[i];
    //     }

    //    }



     
        
      



};