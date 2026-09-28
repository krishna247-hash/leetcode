class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // Find peak
        int low = 1;
        int high = n - 2;
        int peak = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int x = mountainArr.get(mid);
            int left = mountainArr.get(mid - 1);
            int right = mountainArr.get(mid + 1);

            if(x > left && x > right) {
                peak = mid;
                break;
            }
            else if(x > left) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        // Check peak
        int peakValue = mountainArr.get(peak);

        if(peakValue == target)
            return peak;

        // Increasing side
        low = 0;
        high = peak - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int x = mountainArr.get(mid);

            if(x == target)
                return mid;

            else if(x > target)
                high = mid - 1;

            else
                low = mid + 1;
        }

        // Decreasing side
        low = peak + 1;
        high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int x = mountainArr.get(mid);

            if(x == target)
                return mid;

            else if(x > target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }
};