class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int l = 0;
        int r = n-1;

        int lm = INT_MIN, rm = INT_MIN;

        int trapped_water = 0;

        while(l < r)
        {
            lm = max(lm, height[l]);
            rm = max(rm, height[r]);

            if(height[l] < height[r])
            {
                trapped_water += (lm - height[l]);
                l++;
            }
            else if(height[r] <= height[l])
            {
                trapped_water += (rm - height[r]);
                r--;
            }
        }

        return trapped_water;
    }
};