class Solution {
public:
    vector<vector<string>> ans;
    
    // Helper function that checks if s[i...j] is a palindrome.
    bool isPalindrome(const string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    // Backtracking function that uses start index.
    void backtrack(int start, const string &s, vector<string>& current) {
        if(start == s.size()) {
            ans.push_back(current);
            return;
        }
        
        // Try all possible end indices for the substring starting at 'start'.
        for(int end = start; end < s.size(); end++){
            // If the current substring s[start...end] is a palindrome,
            // then add it to the current partition and proceed recursively.
            if(isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, current);
                current.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> current;
        backtrack(0, s, current);
        return ans;
    }
};
