class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        // 

        int element1 = INT_MIN, element2 = INT_MIN;
        int count1 = 0, count2 = 0;

        for(int i = 0; i < n; i++)
        {
            if(count1 == 0 && nums[i] != element2)
            {
                element1 = nums[i];
                count1++;
            }
            else if(count2 == 0 && nums[i] != element1)
            {
                element2 = nums[i];
                count2++;
            }
            else if(nums[i] == element1)
            {
                count1++;
            }
            else if(nums[i] == element2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for(int i = 0; i < n; i++)
        {
            if(element1 == nums[i]) count1++;
            if(element2 == nums[i]) count2++;
        }

        cout << element1 << " " << element2 << endl;

        set<int> ans;

        if(count1 >= n/3 + 1) ans.insert(element1);

        if(count2 >= n/3 + 1) ans.insert(element2);

        return vector<int>(ans.begin(), ans.end());

        
    }
};