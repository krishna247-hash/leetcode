#define ll long long
class Solution {
public:

  bool check(ll n)
{
    if(n < 0) return false;
    ll l = 0, r = n;
    while(l <= r)
    {
        ll mid = l + (r-l)/2;
        if(mid == 0)
        {
            if(n == 0) return true;
            l = 1;
        }
        else if(mid == n/mid && n%mid == 0) return true;
        else if(mid > n/mid) r = mid-1;
        else l = mid+1;
    }
    return false;
}
    
    bool judgeSquareSum(int c) {
        if(c == 0 || c == 1) return 1;
        for(ll i = 0; i == 0 || i <= (c-1)/i; i++)
        {
            ll x = c - i * i;
            if(x == 0) return 1;
            if(check(x)) return 1;
        }

        return 0;
    }
};