class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // Find peak
        int low = 0;
        int high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }

        int peak = low;

        // Search increasing part
        low = 0;
        high = peak;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) == target)
                return mid;

            if (mountainArr.get(mid) < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // Search decreasing part
        low = peak + 1;
        high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) == target)
                return mid;

            if (mountainArr.get(mid) > target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};