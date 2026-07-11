class Solution {
public:
    bool isPalindrome(int x) {
        int org = x;
        int rev = 0;
        int digit;
        if (org<0){
            return false;

        }
        while(x>0){
            digit = x %10;
            rev = rev*1l *10 +digit;
            x = x/10;
        }

        return org==rev;
        }
       
};