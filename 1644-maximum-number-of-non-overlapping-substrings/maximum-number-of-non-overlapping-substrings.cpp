class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) 
    {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // first and last occurrence
        for(int i = 0; i < n; i++)
        {
            int ch = s[i] - 'a';

            first[ch] = min(first[ch], i);
            last[ch] = i;
        }

        vector<pair<int,int>> intervals;

        // Make valid intervals
        for(int c = 0; c < 26; c++)
        {
            if(last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            for(int i = l; i <= r; i++)
            {
                int ch = s[i] - 'a';

                if(first[ch] < l)
                {
                    valid = false;
                    break;
                }

                r = max(r, last[ch]);
            }

            if(valid)
            {
                intervals.push_back({l, r});
            }
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end(),
            [](pair<int,int>& a, pair<int,int>& b)
            {
                return a.second < b.second;
            });

        vector<string> ans;

        int prev = -1;

        for(auto it : intervals)
        {
            int l = it.first;
            int r = it.second;

            if(l > prev)
            {
                ans.push_back(s.substr(l, r - l + 1));
                prev = r;
            }
        }

        return ans;
    }
};