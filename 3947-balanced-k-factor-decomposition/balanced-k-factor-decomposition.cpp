class Solution {
public:
    vector<int> ans;
    int mn = INT_MAX;
    vector<int> current;

    void fn(int n, int k){

        if(k == 0){
            if(n == 1 && !current.empty()){
                int mini = *min_element(current.begin(), current.end());
                int maxi = *max_element(current.begin(), current.end());
                int diff = maxi - mini;
                if (diff < mn) {
                    mn = diff;
                    ans = current;
                }
            }
            
            return;
        }

        for(int i = 1; i * i <= n; i++){
            if(n%i != 0) continue;

            current.push_back(i);
            fn(n/i, k-1);
            current.pop_back();

            current.push_back(n/i);
            fn(i, k-1);
            current.pop_back();
        }
    }

    vector<int> minDifference(int n, int k) {
        ans.clear();
        current.clear();
        mn = INT_MAX;

        fn(n, k);

        return ans;
    }
};