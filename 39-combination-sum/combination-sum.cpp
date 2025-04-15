class Solution {
public:
    void fn(int i, vector<int>& candidates, int rem, vector<int>& temp, set<vector<int>>& result)
    {
        if(rem == 0)
        {
            vector<int> sorted_temp = temp; // we have to create a new vector because if we modify the original temp then we will run into problems when we backtrack.
            result.insert(sorted_temp);
            return;
        }

        if(i < 0) return;
        
        // pick
        if(rem - candidates[i] >= 0)
        {
            temp.push_back(candidates[i]);
            fn(i, candidates, rem - candidates[i], temp, result);
            temp.pop_back();
        }

        // not pick
        fn(i-1, candidates, rem, temp, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;

        set<vector<int>> result;
        
        fn(n-1, candidates, target, temp, result);

        vector<vector<int>> ans(result.begin(), result.end());
        return ans;
    }
};