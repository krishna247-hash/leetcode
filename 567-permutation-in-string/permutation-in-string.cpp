class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return 0;
        vector<int> arr1(26,0);
        for(auto it: s1)
        {
            arr1[it - 'a']++;
        }
        int x = s1.size();
        for(int i = 0; i <= s2.size()-x; i++)
        {
            vector<int> arr2(26,0);
            for(int j = i; j < i+x; j++)
            {
                arr2[s2[j] - 'a']++;
            }
            if(arr1 == arr2) return 1;
        }

        return 0;
    }
};