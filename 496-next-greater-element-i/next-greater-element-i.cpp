class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> ans(n);

        for(int i = 0; i < n; i++)
        {
            int next_greater = nums1[i];

            int j = 0;
            
            while(nums2[j] != nums1[i]) j++;

            for(int k = j; k < m; k++)
            {
                if(nums2[k] > nums1[i])
                {
                    next_greater = nums2[k];
                    break;
                }
            }

            if(next_greater == nums1[i])
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = next_greater;
            }
        }

        return ans;
    }
};