class Solution {
public:
    vector<vector<int>> res;

    void dfs(int i, int rem, vector<int>& candidates, vector<int>& curr) {
        if(rem == 0) {
            res.push_back(curr);
            return;
        }

        for(int j = i; j < candidates.size(); j++) {
            if(j > i && candidates[j] == candidates[j - 1])
                continue;
            if(candidates[j] > rem)
                break;
            curr.push_back(candidates[j]);
            dfs(j + 1, rem - candidates[j], candidates, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(0, target, candidates, curr);
        return res;
    }
};
