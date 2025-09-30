class Solution {
public:
    int signFunc(int& x){
        if(x > 0) return 1;
        else if(x < 0) return -1;

        return 0;
    }

    int arraySign(vector<int>& nums) {
        int val = 1;
        for(auto a : nums) val *= signFunc(a);

        return signFunc(val);
    }
};