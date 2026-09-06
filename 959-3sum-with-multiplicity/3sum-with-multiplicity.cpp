class Solution {

public:

    const long long MOD = 1e9+7;

    int threeSumMulti(vector<int>& arr, int target) {

        long long cnt = 0;

        int n = arr.size();

        sort(arr.begin(), arr.end());

        for(int i = 0; i < n - 2; i++)

        {

            int left = i + 1;

            int right = n - 1;

            while(left < right)

            {

                long long sum = (long long)arr[i] + arr[left] + arr[right];

                if(sum == target)

                {

                    if(arr[left] == arr[right])

                    {

                        long long len = right - left + 1;

                        cnt += len * (len - 1) / 2;

                        cnt %= MOD;

                        break;

                    }

                    else

                    {

                        long long leftCount = 1;

                        long long rightCount = 1;

                        while(left + 1 < right &&

                              arr[left] == arr[left + 1])

                        {

                            leftCount++;

                            left++;

                        }

                        while(right - 1 > left &&

                              arr[right] == arr[right - 1])

                        {

                            rightCount++;

                            right--;

                        }

                        cnt += leftCount * rightCount;

                        cnt %= MOD;

                        left++;

                        right--;

                    }

                }

                else if(sum < target)

                {

                    left++;

                }

                else

                {

                    right--;

                }

            }

        }

        return cnt;

    }

};