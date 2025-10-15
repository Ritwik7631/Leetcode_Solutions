class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();

        int maxi = INT_MIN;
        int mini = INT_MAX;
        double sum = 0;

        for(int i = 0; i < n; i++){
            maxi = max(maxi, salary[i]);
            mini = min(mini, salary[i]);

            sum += salary[i];
        }

        return (sum - maxi - mini) / (n-2);
    }
};