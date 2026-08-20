class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> temp;
        int j = 0;
        int cnt = 0;
        while(j < n-1){
            for(int i = j+1; i < n; i++){
                if(nums[j] == nums[i]){
                  temp.push_back(nums[j]);
                  cnt++;
               
                 } 

            }
            if(cnt == 2) return temp;
            j++;
        }
       return temp;
    }
};