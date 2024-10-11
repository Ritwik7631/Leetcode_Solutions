#define ll long long
class Solution {
public:
    ll ans = 0;
    void Merge(vector<int>& nums, ll i, ll j)
    {
        if(j - i < 1) return;

        ll mid = (i+j)/2;

        Merge(nums, i, mid);
        Merge(nums, mid + 1, j);

        vector<int> temp(j-i+1);

        ll p1 = i;
        ll p2 = mid + 1;
        ll p3 = 0;

        ll p4 = p1;
        ll p5 = p2;
        
        while(p5 <= j && p4 < mid + 1)
        {
            if(nums[p4] <= nums[p5] * 2ll )
            {
                p4++;
            }
            else
            {
                // cout << p4 << " " << p5 << endl;
                // cout << nums[p4] << " " << nums[p5] << endl;
                // cout << endl;

                ans += (mid - p4 + 1);
                p5++;
            }
        }

        while(p2 <= j && p1 < mid + 1)
        {
            if(nums[p1] <= nums[p2])
            {
                temp[p3] = nums[p1];
                p1++;
            }
            else
            {
                temp[p3] = nums[p2];
                p2++;
            }

            p3++;
        }

        while(p2 <= j)
        {
            temp[p3] = nums[p2];
            p2++;
            p3++;
        }

        while(p1 < (i+j)/2 + 1)
        {
            temp[p3] = nums[p1];
            p1++;
            p3++;
        }

        p1 = i;
        p3 = 0;

        while(p1 <= j)
        {
            nums[p1] = temp[p3];
            p3++;
            p1++;
        }

        return;
    }


    int reversePairs(vector<int>& nums) {
        Merge(nums, 0, nums.size()-1);

        return ans;
    }
};