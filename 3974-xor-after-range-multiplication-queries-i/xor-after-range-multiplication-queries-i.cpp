class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        /*
            nums arr of lengthn n
            2d array called queries of size q where queries[i] = [l,r,k,v]

            For each query I do an action in following order
            1. idx = l
            2. While idx <= r
                update nums[idx] = (nums[idx] * v) % 1e9+7
                update idx = idx + k
            
            
            My objective is to return the bitwise XOR of ALL ELEMENTS IN NUMS after processing ALL queries.

            Essentially each query is modifying my input nums array and after performing all queries I want to return the final XOR.

            1e3 for nums array

            nums[i] can be 1e9

            1e3 for # of queries

            l < r && k <= n && v can be 1e5

            The while loop starts at l goes until r and incremements by k
            so the number of loops will be (r-l)/k + 1
            l = 15 r = 40
            k = 7
            15 -> 22 -> 29 -> 36 -> 43X ans: 4
            (40-15)/7 = 4 ceil division

            The brute force tc in worst case would be queries_length*# of while loop runs
                                                      1e3           *1e3 = 1e6 TOO MUCH
            
            nums = [2,3,1,5,4], queries = [[1,4,2,3],[0,2,1,2]]

            Lets say I take the xor before any queries.

            xor before: 1

        */

        int n = nums.size();
        int q = queries.size();
        int mod = 1e9+7;

        for(int i = 0; i < q; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            int idx = l;

            while(idx <= r){
                nums[idx] = (1LL * nums[idx] * v) % (mod);
                idx += k;
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            ans = ans ^ nums[i];
        }

        return ans; 
         
    }
};