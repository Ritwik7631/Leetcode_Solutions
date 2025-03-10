class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1;
        set<int> n2;

        set<int> common;

        for(auto a : nums1)
        {
            n1.insert(a);
        }

        for(auto a : nums2)
        {
            n2.insert(a);
        }

        for(auto a : n1)
        {
            if(n2.count(a))
            {
                common.insert(a);
            }
        }

        for(auto a : n2)
        {
            if(n1.count(a))
            {
                common.insert(a);
            }
        }

        return vector<int> (common.begin(), common.end());
    }
};