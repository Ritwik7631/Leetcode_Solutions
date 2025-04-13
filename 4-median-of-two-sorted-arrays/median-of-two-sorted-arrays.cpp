class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        
        1 7 8 9 12 34 56                    10 13 24 76
            l r                    l           lr
            m                                   m           

        
        0 1 2 3 4 5 6 7 8 9 10
        
        */

        int n = nums1.size();
        int m = nums2.size();

        if(m < n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int total = n + m;

        int l = 0;
        int r = n;

        while(l <= r)
        {
            int partition1 = l + (r-l)/2;

            int partition2 = (total+1)/2 - partition1;

            int max1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int min1 = (partition1 == n) ? INT_MAX : nums1[partition1];

            int max2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int min2 = (partition2 == m) ? INT_MAX : nums2[partition2];

            if(max1 <= min2 && max2 <= min1)
            {
                if(total%2 == 1)
                {
                    return max(max1, max2);
                }
                else
                {
                    return (max(max1,max2) + min(min1, min2)) / 2.0;
                }
            }
            else if(max1 > min2)
            {
                r = partition1 - 1;
            }
            else
            {
                l = partition1 + 1;
            }
        }

        return 0.0;
    }
};