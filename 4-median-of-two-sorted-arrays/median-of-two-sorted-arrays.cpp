class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Optional: Ensure binary search is done on the smaller array.
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
            
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        // For proper partitioning: left part has (total+1)/2 elements.
        int e = (total + 1) / 2;
        
        // Partition index for nums1 can be in [0, n]
        int l = 0;
        int r = n;
        
        double ans = 0;
        
        while(l < r) {
            int mid = l + (r - l) / 2;  // candidate partition index in nums1
            int rem = e - mid;          // corresponding partition index in nums2
            
            // Adjusted indices:
            // For nums1, left part ends at index mid-1 and right part starts at mid.
            int s1 = mid - 1;
            int e1 = mid;
            // For nums2, left part ends at index rem-1 and right part starts at rem.
            int s2 = rem - 1;
            int e2 = rem;
            
            int a = (s1 < 0 ? INT_MIN : nums1[s1]);
            int b = (e1 >= n ? INT_MAX : nums1[e1]);
            int c = (s2 < 0 ? INT_MIN : nums2[s2]);
            int d = (e2 >= m ? INT_MAX : nums2[e2]);
            
            // If partitions are correct:
            if(a <= d && c <= b) {
                if(total % 2 == 0)
                    ans = (max(a, c) + min(b, d)) / 2.0;
                else
                    ans = max(a, c);
                return ans;
            }
            else if(a > d) {
                // Too many elements from nums1, move left.
                r = mid;
            }
            else {
                // Too few elements from nums1, move right.
                l = mid + 1;
            }
        }
        
        // When l == r, use that partition index.
        int mid = l;
        int rem = e - mid;
        int s1 = mid - 1;
        int e1 = mid;
        int s2 = rem - 1;
        int e2 = rem;
        
        int a = (s1 < 0 ? INT_MIN : nums1[s1]);
        int b = (e1 >= n ? INT_MAX : nums1[e1]);
        int c = (s2 < 0 ? INT_MIN : nums2[s2]);
        int d = (e2 >= m ? INT_MAX : nums2[e2]);
        
        if(total % 2 == 0)
            ans = (max(a, c) + min(b, d)) / 2.0;
        else
            ans = max(a, c);
            
        return ans;
    }
};