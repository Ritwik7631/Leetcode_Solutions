class Solution {
public:
    double average(vector<int>& salary) {
        double n = salary.size();
        sort(salary.begin(), salary.end());
        double ans = accumulate(salary.begin() + 1, salary.begin() + n - 1, 0);
        ans /= (n-2.0);

        return ans;
    }
};