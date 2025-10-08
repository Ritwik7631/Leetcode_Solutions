class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = INT_MIN;

        for(auto row : accounts){
            int sum = accumulate(row.begin(), row.end(), 0);
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};