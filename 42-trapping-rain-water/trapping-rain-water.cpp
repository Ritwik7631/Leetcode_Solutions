class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int trapped_water = 0;

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        int left_max = 0;
        int right_max = 0;

        for(int i = n-1; i >= 0; i--)
        {
            left_max = max(left_max, height[i]);
            left[i] = left_max;
        }

        for(int i = 0; i < n; i++)
        {
            right_max = max(right_max, height[i]);

            right[i] = right_max;
        }

        for(int i = 0; i < n; i++)
        {
            trapped_water += min(left[i], right[i]) - height[i];
        }

        return trapped_water; 
    }
};