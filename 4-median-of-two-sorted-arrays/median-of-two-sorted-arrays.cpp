class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
                if(nums2.size() < nums1.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = nums1.size();
        int m = nums2.size();

        int total = n + m;

        int l = 0;
        int r = n;

        while(l <= r)
        {
            int partition1 = l + (r-l)/2;
            
            int partition2 = (total+1)/2 - partition1;

            int mx1 = (partition1 == 0) ? INT_MIN : nums1[partition1-1];
            int mx2 = (partition2 == 0) ? INT_MIN : nums2[partition2-1];

            int mn1 = (partition1 == n) ? INT_MAX : nums1[partition1];
            int mn2 = (partition2 == m) ? INT_MAX : nums2[partition2];

            int mx = max(mx1, mx2);
            int mn = min(mn1, mn2);

            if(mx <= mn)
            {
                if(total % 2 == 0)
                {
                    return (mx + mn) / 2.0;
                }
                else
                {
                    return mx;
                }
            }
            else if(mx1 > mn2) // we picked too many elements from arr1
            {
                r = partition1 - 1;
            }
            else if(mx2 > mn1) // we picked too few elements from arr1
            {
                l = partition1 + 1;
            }

            /*
            The way we can solve this problem is by using binary search. Specifically our search space is the smaller of the two arrays. so l = 0 and r = n. Definitionally the median is 
            equal to the total (n+m)/2 so we need to find a partition in the both arrays. for the partition in the first array we can do mid = l + (r-l)/2, and the partition in the second array
            can be found by doing partition2 = (n+m)/2 - partition1. Lets say there are x elements to the left of the median, and we already occupied mid number of elements in the first array so
            we can only pick x - mid number of elements in the second array.

            Now we need to check if the partition is correct. So up till now we have selected the first partition1 elements from the first array and the first partition2 elements from the second array.

            what we have to do is take the max of the partition1 and partition2 and the min of the elements after partition1 in first array and after partition2 in second array. This is the happy scenario

            but what happens if the max max(partition1, partition2) is greater than the min of the elements after partition1 in first array and after partition2 in second array. Now the natural question 
            is do we move the partition1 to the left or right. We dont need to worry about partition2 because the number of elements we pick is a function of partition1

            lets take an example to understand this better.

            arr1 = [1, 3, 5, 7, 9]
            arr2 = [2, 4, 6, 8, 10]

            total = 10
            
            if we pick 2 elements from arr1

            1, 3
            
            then we can only pick 10/2 - 2 = 3 elements from arr2

            2, 4, 6

            The max calculation is max(3,6) = 6

            The min calculation is min(5,8) = 5

            since mx > mn this tells us that we picked too many elements in the first array and too few in the second array. So we need to move the partition1 to the left.

            so intially our search space is from l = 0 to r = 5.
            
            we pick partition1 = l + (r-l)/2 = 0 + (5-0)/2 = 2
            
            partition2 = (total/2) - partition1 = 10/2 - 2 = 3

            and now how do we get the 3 from 1,3 and how do we get the 6 from 2,4,6

            mx1 = arr1[partition1-1] = arr1[2-1] = 3 

            mx2 = arr2[partition2-1] = arr2[3-1] = 6

            mx = max(mx1, mx2) = max(3,6) = 6

            mn1 = arr1[partition1] = arr1[2] = 5

            mn2 = arr2[partition2] = arr2[3] = 8

            mn =min(mn1, mn2) = min(5,8) = 5

            since mx > mn we need to have to pick fewer elements from the first array and more elements from the second array.

            so we update l = partition1 + 1 = 2 + 1 = 3

            ok so now l = 3 and r = 5

            so partition1 = l + (r-l)/2 = 3 + (5-3)/2 = 4
            
            partition2 = (total/2) - partition1 = 10/2 - 4 = 1

            mx1 = arr1[partition1-1] = arr1[4-1] = 7

            mx2 = arr2[partition2-1] = arr2[1-1] = 2

            mx = max(mx1, mx2) = max(7,2) = 7

            mn1 = arr1[partition1] = arr1[4] = 9

            mn2 = arr2[partition2] = arr2[1] = 4

            mn = min(mn1, mn2) = min(9,4) = 4

            now we have mn and mx we see that mx > mn -> 7 > 4 so we need to pick more elements from the first array and fewer elements from the second array.

            so we update l = partition1 + 1 = 4 + 1 = 5

            now l = 5 and r = 5 so we pick partition1 = l + (r-l)/2 = 5 + (5-5)/2 = 5

            partition2 = (total/2) - partition1 = 10/2 - 5 = 0

            mx1 = arr1[partition1-1] = arr1[5-1] = 9

            mx2 = arr2[partition2-1] = arr2[0-1] = 1 we have to consider the case where partition2 is 0
            
            if partition2 is 0 then mx2 is -infinity

            mx = max(mx1, mx2) = max(9, -infinity) = 9

            mn1 = arr1[partition1] = arr1[5] = 10
            
            mn2 = arr2[partition2] = arr2[0] = 2 we have to consider the case where partition2 is 0

            if partition2 is 0 then mn2 is infinity

            mn = min(mn1, mn2) = min(10, infinity) = 10

            since mx <= mn we need to have to pick more elements from the first array and fewer elements from the second array.

            so we update r = partition1 - 1 = 5 - 1 = 4

            now l = 3 and r = 4

            so partition1 = l + (r-l)/2 = 3 + (4-3)/2 = 3

            partition2 = (total/2) - partition1 = 10/2 - 3 = 2

            mx1 = arr1[partition1-1] = arr1[3-1] = 5

            mx2 = arr2[partition2-1] = arr2[2-1] = 4    

            mx = max(mx1, mx2) = max(5,4) = 5

            mn1 = arr1[partition1] = arr1[3] = 7

            mn2 = arr2[partition2] = arr2[2] = 6            

            mn = min(mn1, mn2) = min(7,6) = 6

            since mx <= mn we need to have to pick more elements from the first array and fewer elements from the second array.

            so we update r = partition1 - 1 = 3 - 1 = 2 

            now l = 3 and r = 2 so we stop the loop

            now we have the correct partitions.

            so we pick the first 3 elements from the first array and the first 2 elements from the second array.

            if total is even then we pick the middle 2 elements from the first array and the middle 2 elements from the second array.
            
            if total is odd then we pick the middle element from the first array and the middle element from the second array.

            so we pick the first 3 elements from the first array and the first 2 elements from the second array.

            This answer makes sense because we merge arr1 and arr2 we get [1,2,3,4,5,6,7,8,9,10] and the median is 5.5

            
            
            */ 
        }

        return 0.0; 
    }
};