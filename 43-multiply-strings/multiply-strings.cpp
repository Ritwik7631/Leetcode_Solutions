class Solution {
public:
    string remove_lead_zeros(string x){
        int i = 0;
        while(i < x.size() && x[i] == '0') i++;
        if(i == x.size()) return "0";
        return x.substr(i);
    }

    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        string ans = "";
        vector<string> inter;

        int place = 0;

        for(int j = m-1; j >= 0; j--){
            string temp = "";
            int carry = 0;
            int b = num2[j] - '0';
            for(int i = n-1; i >= 0; i--){
                int a = num1[i] - '0';
                int product = (a*b) + carry;
                int digit = product % 10;
                carry = product / 10;

                temp += (digit + '0');
            }

            if(carry) temp += (carry + '0');

            reverse(temp.begin(), temp.end());            

            for(int k = 0; k < place; k++) temp += '0';

            inter.push_back(temp);
            place++;
        }

        string current_sum = "0";

        for(auto a : inter){
            int n = current_sum.size();
            int m = a.size();

            int i = n-1;
            int j = m-1;
            int carry = 0;

            string temp_sum = "";

            while(i >= 0 || j >= 0 || carry){
                int x = 0, y = 0;

                if(i >= 0) x = current_sum[i] - '0';
                if(j >= 0) y = a[j] - '0';

                int sum = x + y + carry;

                int digit = sum % 10;
                carry = sum / 10;

                temp_sum += (digit + '0');

                i--;
                j--;
            }

            reverse(temp_sum.begin(), temp_sum.end());
            current_sum = remove_lead_zeros(temp_sum);
        }

        return current_sum;
    }
};