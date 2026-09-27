class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> mp;
        if(hand.size() % groupSize != 0) return 0;
        for(auto it: hand) mp[it]++;
        sort(hand.begin(),hand.end());
        for(int i = 0; i <= hand.size()-groupSize; i++)
        {
            if(mp[hand[i]] > 0)
            {
                int x = hand[i];
                for(int i = 0; i < groupSize; i++)
                {
                    if(mp[x+i] <= 0) return 0;
                    mp[x+i]--;
                }

            }
        }

        return 1;
    }
};