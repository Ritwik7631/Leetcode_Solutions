class Solution {
public:    
    int sortPermutation(vector<int>& nums) {
            // seems like a binary search problem
            // what is min value of k and max value of k
            // k is non-negative so therefore k = 0 for min
            // max k = 99999 & 99999 == 99999 (Essentially 2 numbers whose binary representation is basically the same)
            // now for any given k how will I determine if I have a valid K?

            // lets try to solve this manually
            // [0 1 3 2]
            // try k = 0
            // i and j must be different otherwise the swapping would not make sense
            // there can be duplicate values
            // i = 0 j = 1 -> 0 & 1 = 0 -> swappable -> choose not to swap since it is already non-decreasing
            // i = 0 j = 2...3 "------------- same as above ----------------------------------------------------"
            // i = 1 j = 2 -> 1 & 3 -> choose not to swap since it is already non-decreasing
            // i = 1 j = 3 -> choose not to swap since it is already non-decreasing
            // i = 2 j = 3 - > 3 & 2 -> 2 != k so can't swap
            // try k = 1
            // i = 0 j = 1...3 -> choose not to swap since it is already non-decreasing
            // i = 1 j = 2...3 -> choose not to swap since it is already non-decreasing
            // i = 2 j = 3 -> 3 & 2 != k so can't swap

            // try k = 2
            // i = 0 j = 1...3 -> choose not to swap since it is already non-decreasing
            // i = 1 j = 2...3 -> choose not to swap since it is already non-decreasing
            // i = 2 j = 3 -> 3 & 2 == 2 == k We will swap and resulting is [0 1 2 3]

            // now one observation is that I dont need to an n^2 approach to iterate through i's and j's.
            // How can I check if a K converts the input so that it is non-decreasing?
            // Maybe I can precompute which i and j give k and then I will swap them if it makes it non-decreasing
            // k : {pairs of i and j that & and give k} - just a thought maybe I only push the pairs where arr[i] <= arr[j]
            // I will use this map to only filter through the pairs whose value == k
            // if i and j are swappable and nums[i] > nums[j] so then I think the answer is to just swap
            
            // --------------------------------------------------------------------------------------------------------
            // Binary search will NOT WORK AT ALL
            // if we try k = 3 this is not valid and so far we have the pattern no, no, yes, no
            // the yes and no have to be monotone y,y,y,n,n,n or n,n,y,y,y

            // The key realization is that for whatever k we choose then x & k == k where x is a misplaced value
            // misplaced value means there are numbers to the left that are bigger than it.
            
            // Then for a given k we determine what is the set of misplaced values in the input. We are grouping here.

            // Essentially the way to get the answer is to aggregate all the misplaced value and bitwise and them to get the largest value of k possible

            // how do I determine what are my misplaced values?

            // [0,2,3,1]

            // i = 0 fine
            // i = 1 fine 2 > 0
            // i = 2 fine 3 > 2 and 3 > 0
            // i = 3 not fine 1 < 2 and 1 < 3 and 1 > 0
            
            // what I can do is record the largest number until now and if my current number is bigger than the largest than keep iterating otherwise we know everything from largest to current is misplaced

            // Wrong the key thing here to realize is that the input only contains all the elements from 0 - n-1 but the order might be incorrect so if nums[i] != i we know it is misplaced

            int n = nums.size();

            bool sorted = true;
            for (int i = 0; i < n; ++i) {
                if (nums[i] != i) { sorted = false; break; }
            }

            if (sorted) return 0;

            int k = ~0;

            for(int i = 0; i < n; i++){
                if(nums[i] != i) k = k & nums[i];
            }

            return k;


    }
};
