class Solution {
public:
    bool caneat(vector<int>& piles, int k, int h)
    {
        int c = 0;

        for(auto a : piles)
        {
            c += (a + k - 1) / k;
        }

        return c <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(), piles.end());

        int l = 1;
        int r = mx;

        while(l < r)
        {
            int mid = l + (r-l)/2;

            if(caneat(piles, mid, h))
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }

        return l;
    }
};