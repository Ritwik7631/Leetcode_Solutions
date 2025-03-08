class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;

        for(int i = 0; i < nums2.size(); i++)
        {   
            int next_greater = -1;
            for(int j = i+1; j < nums2.size(); j++)
            {
                if(nums2[j] > nums2[i])
                {
                    next_greater = nums2[j];
                    break;
                }
            }

            mp[nums2[i]] = next_greater;
        }

        vector<int> ans;

        for(auto a : nums1)
        {
            ans.push_back(mp[a]);
        }

        return ans;
    }
};