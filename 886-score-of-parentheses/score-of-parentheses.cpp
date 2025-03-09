class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;

        int ans = 0;

        for(auto a : s)
        {
            if(a == '(')
            {
                stk.push(ans);
                ans = 0;
            }
            else
            {
                ans = stk.top() + max(2*ans, 1);
                stk.pop();
            }
        }

        return ans;
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