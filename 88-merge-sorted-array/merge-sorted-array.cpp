class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p2 = n-1;
        int p3 = n+m-1;
        int p1 = m-1;

        while(p2 >= 0 && p1 >= 0)
        {
            if(nums1[p1] > nums2[p2])
            {
                nums1[p3] = nums1[p1];
                p1--;
            }
            else 
            {
                nums1[p3] = nums2[p2];
                p2--;
            }

            p3--;
        }

        while(p1 >= 0)
        {
            nums1[p3] = nums1[p1];
            p1--;
            p3--;
        }

        while(p2 >= 0)
        {
            nums1[p3] = nums2[p2];
            p2--;
            p3--;
        }

        return;
    }
};

/*
    p1
1 2 5 1 1 2 2 4 5
                p3

1 1 2 2 4 5
p2


 
*/