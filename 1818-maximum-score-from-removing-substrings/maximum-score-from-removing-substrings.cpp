class Solution {
public:
    int ba(string &s)
    {
        stack<char> stk;
        int count = 0;
        for(auto a : s)
        {
            if(stk.empty())
            {
                stk.push(a);
                continue;
            } 

            if(a == 'a' && stk.top() == 'b')
            {
                stk.push(a);
                stk.pop();
                stk.pop();
                count++;
            }
            else
            {
                stk.push(a);
            }
        }

        string temp = "";

        while(!stk.empty())
        {
            char ch = stk.top();
            temp += ch;
            stk.pop();
        }

        reverse(temp.begin(), temp.end());
        s = temp;

        return count;
    }
    int ab(string &s)
    {
        stack<char> stk;
        int count = 0;
        for(auto a : s)
        {
            if(stk.empty())
            {
                stk.push(a);
                continue;
            } 

            if(a == 'b' && stk.top() == 'a')
            {
                stk.push(a);
                stk.pop();
                stk.pop();
                count++;
            }
            else
            {
                stk.push(a);
            }
        }

        string temp = "";

        while(!stk.empty())
        {
            char ch = stk.top();
            temp += ch;
            stk.pop();
        }

        reverse(temp.begin(), temp.end());
        s = temp;
        return count;
    }
    int maximumGain(string s, int x, int y) {
        // first thought recursion!
        // second thought thinking of greedy approach

        string a = s;
        string b = s;

        int ans1 = x*ab(a) + y*ba(a);
        int ans2 = y*ba(b) + x*ab(b);
        return max(ans1,ans2);
    }
};