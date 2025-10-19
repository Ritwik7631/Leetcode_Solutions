class Solution {
public:
    string remove_zeros(string x){
        int n = x.size();

        int i = 0;

        while(i < n && x[i] == '0') i++;
        
        return x.substr(i);
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();

        vector<int> ans(n+m, 0);

        for(int j = m-1; j >= 0; j--){
            for(int i = n-1; i >= 0; i--){
                int offset = (n-1-i) + (m-1-j);
                int prod = (num1[i] - '0') * (num2[j] - '0');
                int sum = prod + ans[offset];
                int digit = sum % 10;
                int carry = (sum / 10);

                ans[offset] = digit;
                ans[offset+1] += carry;
            }
        }

        string result_string = "";
        for(auto a : ans) result_string += to_string(a);
        
        reverse(result_string.begin(), result_string.end());

        result_string = remove_zeros(result_string);

        return result_string;
    }
};