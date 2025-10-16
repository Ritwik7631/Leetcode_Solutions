class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();

        int i = n-1;
        int j = m-1;
        int carry = 0;

        string ans = "";

        while(i >= 0 && j >= 0){
            int x = a[i] - '0';
            int y = b[j] - '0';

            int sum = x + y + carry;

            int digit = sum % 2;
            carry = sum/2;

            ans += (digit + '0');

            i--;
            j--;
        }

        while(i >= 0){
            int x = a[i] - '0';

            int sum = x + carry;

            int digit = sum % 2;
            carry = sum/2;

            ans += (digit + '0');

            i--;
        }

        while(j >= 0){
            int y = b[j] - '0';

            int sum = y + carry;

            int digit = sum % 2;
            carry = sum/2;

            ans += (digit + '0');

            j--;
        }

        if(carry) ans.push_back(carry + '0');

        reverse(ans.begin(), ans.end());

        return ans;
    }
};