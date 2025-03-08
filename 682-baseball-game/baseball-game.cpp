class Solution {
public:
    bool isnum(string x)
    {
        for(auto a : x)
        {
            char y = a;
            int digit = y - '0';

            if(!(digit >= 0 && digit <= 9)) return false;
        }

        return true;
    }

    int calPoints(vector<string>& operations) {
        stack<int> scores;

        for(auto a : operations)
        {
            if(a[0] == '-')
            {
                string temp(a.begin()+1, a.end());

                if(isnum(temp)) scores.push(-1 * stoi(temp));
            }
            
            if(isnum(a)) scores.push(stoi(a));

            if(a == "+")
            {
                int x = scores.top();
                scores.pop();
                int y = scores.top();
                scores.pop();

                scores.push(y);
                scores.push(x);
                scores.push(y+x);
                
                // cout << "+" << " " << endl;
                // cout << y << " " << x << " " << y+x << " " << endl;
            }

            if(a == "D")
            {
                int x = scores.top();
                scores.pop();

                scores.push(x);
                scores.push(x*2);
                
                // cout << "D" << endl;
                // cout << x << " " << x*2 << " " << endl;
            }

            if(a == "C")
            {
                scores.pop();
            }
        }
        int ans = 0;
        while(!scores.empty())
        {
            ans += scores.top();
            scores.pop();
        }

        return ans;
    }
};