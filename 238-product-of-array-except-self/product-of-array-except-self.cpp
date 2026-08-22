class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        int mul = 1;
        int cnt = 0;
        int zero;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
               cnt++;
               zero = i;
            }
            else{
                mul *= nums[i]; 
            }
            
        }

        if(cnt == 0){
            for(int i = 0; i < n; i++){
                int s = mul / nums[i];
                temp.push_back(s);
            }

            return temp;
        }
        else
        {
           if(cnt == 1){
            for(int i = 0; i < n; i++){
                if(i == zero){
                    temp.push_back(mul);
                }
                else{
                    temp.push_back(0);
                }
            }
           }
           else{
            for(int i = 0; i < n; i++){
                temp.push_back(0);
            }
           }
            
        }
        return temp;
    }
};