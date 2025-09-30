class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        int carry = 0;
        bool flag = true;
        for(int i = n-1; i >= 0; i--){
            if(i == n-2) flag = false;

            int val = digits[i] + flag + carry;

            int digit = val%10;
            ans.push_back(digit);
            carry = val/10;
        }

        if(carry != 0) ans.push_back(carry);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};