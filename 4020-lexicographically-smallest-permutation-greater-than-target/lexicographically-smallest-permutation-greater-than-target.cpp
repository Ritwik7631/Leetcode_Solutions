class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> bank(26,0);

        for(auto a : s) bank[a-'a']++;

        string ans = "";

        int i = -1;
        for(char a : target){
            i++;
            if(bank[a-'a'] > 0){
                bank[a-'a']--;
                ans += a;
            }
            else break;
        }

        if(ans.size() != target.size()){
            int letter = target[i] - 'a';
            for(int k = letter+1; k < 26; k++){
                if(bank[k] > 0){
                    ans += (k + 'a');
                    bank[k]--;
                    for(int t = 0; t < 26; t++) ans += string(bank[t], t+'a');
                    return ans;
                }
            }
        }

        for(int j = ans.size()-1; j >= 0; j--){
            int index = ans[j] - 'a';
            bank[index]++;
            for(int k = index+1; k < 26; k++){
                if(bank[k] > 0){
                    ans[j] = (k + 'a');
                    bank[k]--;
                    ans = ans.substr(0, j+1);
                    for(int t = 0; t < 26; t++){
                        ans += string(bank[t], t+'a');
                    }
                    return ans;
                }
            }
        }

        return "";
    }
};