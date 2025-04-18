class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       multiset<int> ms(nums.begin(), nums.end());

       while(ms.size() > k)
       {
            auto it = ms.begin();
            ms.erase(it);
       }

       return *ms.begin();
    }
};