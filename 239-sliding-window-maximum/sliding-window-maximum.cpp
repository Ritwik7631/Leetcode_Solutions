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
                ans.push_back(*mxs.rbegin());
                mxs.erase(mxs.find(nums[a])); // only deleting one instance of nums[a] NOT ALL
                a++;
                c--;
            }
        }
        
        return ans;
    }
};
