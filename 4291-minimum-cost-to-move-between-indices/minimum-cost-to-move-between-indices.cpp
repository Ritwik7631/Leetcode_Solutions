class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> lomviretas = nums;

        vector<int> closest(n);

        closest[0] = 1;
        closest[n-1] = n-2;

        for(int i = 1; i < n-1; i++){
            if(abs(nums[i] - nums[i-1]) <= abs(nums[i] - nums[i+1])){
                closest[i] = i-1;
            }
            else{
                closest[i] = i+1;
            }
        }

        vector<long long> leftcost(n, 0), rightcost(n, 0);

        for(int i = 1; i < n; i++){
            if(closest[i] == i-1) leftcost[i] = 1;
            else leftcost[i] = abs(nums[i] - nums[i-1]);
        }

        for(int i = 0; i < n-1; i++){
            if(closest[i] == i+1) rightcost[i] = 1;
            else rightcost[i] = abs(nums[i] - nums[i+1]);
        }

        vector<long long> preleft(n), preright(n);

        long long sum = 0;

        for(int i = 1; i < n; i++){
            sum += leftcost[i];
            preleft[i] = sum;
        }

        sum = 0;

        for(int i = 0; i < n-1; i++){
            sum += rightcost[i];
            preright[i+1] = sum;
        }

        vector<int> ans(m);

        for(int i = 0; i < m; i++){
            int l = queries[i][0], r = queries[i][1];

            if(l < r){
                ans[i] = preright[r] - preright[l];
            }
            else{
                ans[i] = preleft[l] - preleft[r];
            }
        }

        return ans;
    }
};
