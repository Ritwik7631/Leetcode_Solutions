class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int,int> nge;

        stack<int> stk;

        for(int i = m-1; i >= 0; i--)
        {
            if(stk.empty())
            {
                nge[nums2[i]] = -1;
            }
            else
            {
                while(!stk.empty() && stk.top() <= nums2[i])
                {
                    stk.pop();
                }

                if(stk.empty())
                {
                    nge[nums2[i]] = -1;
                }
                else
                {
                    nge[nums2[i]] = stk.top();
                }
            }

            stk.push(nums2[i]);
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++)
        {
            ans[i] = nge[nums1[i]];
        }

        return ans;
    }
};