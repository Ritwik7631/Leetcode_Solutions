class Solution {
public:
    vector<string> ans;

    void dfs(int current_digit, string& curr_combo, unordered_map<int, vector<string>>& mp, string& digits) {
        if (current_digit == digits.size()) {
            ans.push_back(curr_combo);
            return;
        }

        for (const string& a : mp[digits[current_digit] - '0']) { 
            curr_combo += a;
            dfs(current_digit + 1, curr_combo, mp, digits);
            curr_combo.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<int, vector<string>> mp = {
            {2, {"a", "b", "c"}},
            {3, {"d", "e", "f"}},
            {4, {"g", "h", "i"}},
            {5, {"j", "k", "l"}},
            {6, {"m", "n", "o"}},
            {7, {"p", "q", "r", "s"}}, // Fixed: 7 has four letters
            {8, {"t", "u", "v"}},
            {9, {"w", "x", "y", "z"}}
        };

        if (digits.size() == 1) return mp[digits[0] - '0']; 

        string temp = "";
        dfs(0, temp, mp, digits);

        return ans;
    }
};
