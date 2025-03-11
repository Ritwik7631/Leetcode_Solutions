class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if(k > n) k = k % n;

        queue<int> q;

        reverse(nums.begin(), nums.end());
        for(auto a : nums) q.push(a);

        queue<int> nw;

        while(k > 0)
        {
            int fr = q.front();
            q.pop();
            nw.push(fr);
            k--;
        }

        int i = 0;
        while(!q.empty())
        {
            nums[i] = q.front();
            q.pop();
            i++;
        }

        while(!nw.empty())
        {
            nums[i] = nw.front();
            nw.pop();
            i++;
        }

        reverse(nums.begin(), nums.end());

        return;
    }
};