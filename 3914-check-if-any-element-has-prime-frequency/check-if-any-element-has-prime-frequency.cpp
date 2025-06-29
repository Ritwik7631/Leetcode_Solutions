class Solution {
public:
    bool isPrime(int x){
        if(x == 2) return true;

        if(x % 2 == 0 || x == 1) return false;

        for(int i = 3; i*i <= x; i += 2)
        {
            if(x % i == 0) return false;
        }

        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto a : nums){
            mp[a]++;
        }

        for(auto a : mp){
            if(isPrime(a.second)){
                return true;
            }
        }

        return false;
    }
};