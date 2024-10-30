class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        int lmax = 0;
        for(int i = 0; i < n; i++)
        {
            lmax = max(lmax, height[i]);
            left[i] = lmax;
        }

        int rmax = 0;
        for(int i = n-1; i >= 0; i--)
        {
            rmax = max(rmax, height[i]);
            right[i] = rmax;
        } 

        int trapped_water = 0;

        for(int i = 0; i < n; i++)
        {
            trapped_water += (min(left[i], right[i]) - height[i]);
        }

        return trapped_water;
    }
};