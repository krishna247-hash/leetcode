class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }


        int i = 0;
        int ct = 0;

        for (auto x : mp) {

            if(x.second > 1){
                nums[i++] = x.first;
                nums[i++] = x.first;
                ct += 2;

            }
            else{
                nums[i++] = x.first;
                ct++;
            }

       

        }

        sort(nums.begin(),nums.begin() + ct);

        return ct;


      
        
    }
};