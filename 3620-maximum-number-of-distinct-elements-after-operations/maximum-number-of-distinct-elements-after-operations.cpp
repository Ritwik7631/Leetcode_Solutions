class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        map<int,int> mp;

        int n = nums.size();

        for(auto a : nums)
        {
            mp[a]++;
        }

        int count = 0;
        int next = INT_MIN;
        for(auto [num, freq] : mp)
        {
            int a = num-k;
            int b = num+k;
            int actual_a, actual_b;

            if(next >= a && next <= b) actual_a = next;
            else actual_a = a;

            if(actual_a+freq-1 > b) actual_b = b;
            else actual_b = actual_a + freq - 1;

            next = actual_b + 1;

            // cout << "actual a: " << actual_a << " actual b: " << actual_b << endl;

            count += (actual_b - actual_a + 1);
        }

        return count;
    }
};