class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int ans = 0;

        int l = 0;
        int r = n-1;

        while(l < r)
        {
            int h = min(height[l], height[r]);

            int w = r - l;

            ans = max(ans, w*h);

            if(height[l] < height[r])
            {
                l++;
            }
            else if(height[l] > height[r])
            {
                r--;
            }
            else
            {
                l++;
            }
        }

        return ans;
    }
};