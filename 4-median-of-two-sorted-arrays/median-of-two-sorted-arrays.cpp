

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // Ensure nums1 is the smaller array to achieve O(log(min(m,n)))
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        
        int lo = 0, hi = m;
        int totalLeft = (m + n + 1) / 2;
        
        while (lo <= hi) {
            int i = (lo + hi) / 2;
            int j = totalLeft - i;
            
            // Get the 4 critical values around the partition, handling boundaries smoothly
            int nums1Left  = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1Right = (i == m) ? INT_MAX : nums1[i];
            
            int nums2Left  = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2Right = (j == n) ? INT_MAX : nums2[j];
            
            // Check if we found the correct partition
            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                // If total number of elements is odd
                if ((m + n) % 2 != 0) {
                    return max(nums1Left, nums2Left);
                }
                // If total number of elements is even
                return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
            }
            // Too many elements from nums1 on the left side, move partition left
            else if (nums1Left > nums2Right) {
                hi = i - 1;
            }
            // Too few elements from nums1 on the left side, move partition right
            else {
                lo = i + 1;
            }
        }
        return 0.0;
    }
};