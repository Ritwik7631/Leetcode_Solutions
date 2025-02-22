class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int a = 0;
        multiset<int> mxs;
        int c = 0;
        
        for (int b = 0; b < n; b++) {
            mxs.insert(nums[b]);
            c++;
            
            while (c == k) {
                ans.push_back(*mxs.rbegin());  // add the maximum element in current window
                // Remove the element that is sliding out (not necessarily the maximum)
                mxs.erase(mxs.find(nums[a]));
                a++;
                c--;
            }
        }
        
        return ans;
    }
};
