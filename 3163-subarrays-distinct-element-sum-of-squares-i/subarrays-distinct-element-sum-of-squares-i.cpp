#define ll int
#define vll vector<ll>
#define vvll vector<vll>

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        vll sub;
        
        for(ll i = 0; i < nums.size(); i++)
        {
            unordered_map<ll,ll> mp;
            ll cnt = 0;
            for(ll j = i; j < nums.size(); j++)
            {
                mp[nums[j]]++;
                if(mp[nums[j]] == 1) cnt++;
                sub.push_back(cnt);
            }

        }


        ll ans = 0;

        for(auto it: sub)
        ans += it*it;

        return ans;
    }
};