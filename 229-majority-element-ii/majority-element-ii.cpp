class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums;
        vector<int> ans;
        int k = n / 3;
        int e1 = INT_MIN; int e2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;

        for(auto it : nums)
        {
            

            if (it == e1)

            {

                cnt1++;

            }

            else if (it == e2)

            {

                cnt2++;

            }

            else if (cnt1 == 0)

            {

                e1 = it;

                cnt1 = 1;

            }

            else if (cnt2 == 0)

            {

                e2 = it;

                cnt2 = 1;

            }

            else

            {

                cnt1--;

                cnt2--;

            }
        }

        cnt1 = 0; cnt2 = 0;
        for(auto it: nums)
        {
            if(it == e1) cnt1++;
            else if(it == e2) cnt2++;
        }

        if(cnt1 > k) ans.push_back(e1);
        if(cnt2 > k) ans.push_back(e2);

        return ans;

    }
};