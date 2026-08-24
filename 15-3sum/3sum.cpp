class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> temp;

        set<vector<int>> st;

        int i = 0; 
        while(i < n-2){
            int ei = nums[i];
            int low = i + 1;
            int high = n-1;

            while(low < high){
                if(( nums[i] + nums[low] + nums[high] ) == 0){
                    st.insert({nums[i],nums[low],nums[high]});
                    low++;
                   
                }
                else if(( nums[i] + nums[low] + nums[high] ) > 0){
                    high--;
                }
                else{
                    low++;
                }

            }
            while(ei == nums[i] && i < n-2){
                i++;
            }
        }

        for(auto it: st){
            temp.push_back(it);
        }
        return temp;


    }
};