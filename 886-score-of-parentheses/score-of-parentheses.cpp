class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        stk.push(0);
        
        for(auto a : s)
        {
            if(a == '(')
            {
                stk.push(0);
            }
            else
            {
                int topval = stk.top();
                stk.pop();

                int computed = max(2*topval, 1);
                stk.top() += computed;
            }
        }

        return stk.top();
    }
};


// class Solution {
// public:
//     int scoreOfParentheses(string s) {
//         stack<char> stk;

//         int ans = 0;

//         int temp = INT_MIN;

//         for(auto a : s)
//         {
//             if(a == '(')
//             {
//                 if(temp != INT_MIN) ans += temp;
//                 temp = INT_MIN;
//                 stk.push(a);
//             }
//             else
//             {
//                 if(temp == INT_MIN)
//                 {
//                     temp = 1;
//                 }
//                 else
//                 {
//                     temp *= 2;
//                 }

//                 stk.pop();
//             }
//         }

//         if(temp != INT_MIN) ans += temp;

//         return ans;
//     }
// };

// // ((()))
// /*

// ((()))


// */