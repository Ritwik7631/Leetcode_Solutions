class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int diff = INT_MIN;

        int n = arr.size();

        if(n == 2) return true;

        for(int i = 1; i < n; i++){
            if(diff == INT_MIN || arr[i] - arr[i-1] == diff){
                diff = arr[i] - arr[i-1];
            }
            else{
                return false;
            }
        }

        return true;
    }
};