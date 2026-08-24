class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());

        int cnt = 1;

        int prior = nums[0];
        vector<int> temp;

        for(int i = 1; i < n; i++){
            if(prior != nums[i]){
                if(cnt > n/3){
                    temp.push_back(prior);

                }

                prior = nums[i];
                cnt = 1;
            }
            else{
                cnt++;
            }
        }

        if (cnt > n / 3) {

            temp.push_back(prior);

        }
        return temp;

    }
};