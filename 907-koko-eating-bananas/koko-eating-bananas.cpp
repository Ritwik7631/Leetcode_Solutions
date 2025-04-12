class Solution {
public:
    bool KokoCanEat(int k, vector<int>& piles, int h)
    {
        int count = 0;

        for(auto a : piles)
        {
            count += (a + k - 1) / k;  // integer version of ceil(a / k)
        }

        return count <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while(l < r)
        {
            int mid = l + (r-l)/2;

            if(KokoCanEat(mid, piles, h))
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }

        return l;

        // l = 20 r = 25
        // mid = 22
        // 2 + 1 + 2 + 1 + 1 = 7
        // l = 23 r = 25
        // mid = 24
        // 2 + 1 + 1 + 1 + 1 = 6
        // l = 23 r = 24
        // mid = 23
        // 2 + 1 + 1 + 1 + 1 = 6
        // r = 23

    }
};