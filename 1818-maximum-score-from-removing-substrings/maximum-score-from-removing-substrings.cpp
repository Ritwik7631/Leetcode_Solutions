class Solution {
public:
    int ba(string &s)
    {
        stack<char> stk;
        int count = 0;
        for(auto a : s)
        {
            if(!stk.empty() && a == 'a' && stk.top() == 'b')
            {
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
            temp += stk.top();
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
            if(!stk.empty() && a == 'b' && stk.top() == 'a')
            {
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
            temp += stk.top();
            stk.pop();
        }
        reverse(temp.begin(), temp.end());
        s = temp;

        return count;
    }

    int maximumGain(string s, int x, int y) {
        // We need to prioritize the higher score removal first
        if (x > y)
        {
            return x * ab(s) + y * ba(s);
        }
        else
        {
            return y * ba(s) + x * ab(s);
        }
    }
};
