class Solution {
public:
    bool isPowerOfTwo(int n) {

        //  using bit manupulation
        // clearing right most bit
        if(n <= 0) return 0;
       if((n & (n-1))) return false;
       return true;
    }
};