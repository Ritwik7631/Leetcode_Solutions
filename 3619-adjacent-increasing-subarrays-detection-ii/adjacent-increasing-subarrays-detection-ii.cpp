class Solution {
public:
    bool fn(vector<int>& arr, int k) {
        int n = arr.size();
        
        for(int i = 0; i < n; i++)
        {

            if(i + k < n) if(arr[i] >= k && arr[i+k] >= k) return true;
        }

        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        // binary search

        // lowest value of k = 1
        // largest value of k = nums.size()/2

        int n = nums.size();

        int lo = 1;
        int hi = n;

        // Precompute the longest increasing subarray length starting at each index
        vector<int> increasing_lengths(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                increasing_lengths[i] = increasing_lengths[i + 1] + 1;
            }
        }

        while(lo < hi)
        {
            int mid = (hi-lo)/2 + lo;
            
            if(fn(increasing_lengths, mid))
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        return lo-1;

    }
};