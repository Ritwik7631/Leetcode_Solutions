class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);

        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                prefix[i] = nums[i];
            }
            else
            {
                prefix[i] = prefix[i-1] * nums[i];
            }
        }

        vector<int> dupl = nums;
        reverse(dupl.begin(), dupl.end());

        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                suffix[i] = dupl[i];
            }
            else
            {
                suffix[i] = suffix[i-1] * dupl[i];
            }
        }

        for(auto a : prefix) cout << a << " ";
        cout << endl;

        for(auto a : suffix) cout << a << " ";
        cout << endl;

        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++)
        {
            int pre = 1, suf = 1;

            if(i-1 >= 0) pre = prefix[i-1];
            if(n - 1 - i - 1 >= 0) suf = suffix[n-2-i];

            ans[i] = suf*pre;
        }

        return ans;
    }
};