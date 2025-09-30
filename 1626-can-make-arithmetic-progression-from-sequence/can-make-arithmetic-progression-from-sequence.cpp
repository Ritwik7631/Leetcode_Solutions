class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();

        if(n == 2) return true;

        int mn = *min_element(arr.begin(), arr.end());
        int mx = *max_element(arr.begin(), arr.end());

        if((mx-mn)%(n-1) != 0) return false;

        int d = (mx - mn) / (n - 1);

        unordered_set<int> st(arr.begin(), arr.end());

        for(int k = 0; k < n; k++){
            if(!st.count(mn + k*d)) return false;
        }

        return true;
    }
};