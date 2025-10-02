class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int n = s.size();

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(i+1 < n){
                if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')){
                    if(s[i+1] == 'V'){
                        ans += 4;
                        i++;
                        continue;
                    }
                    else{
                        ans += 9;
                        i++;
                        continue;
                    }
                }
                else if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')){
                    if(s[i+1] == 'L'){
                        ans += 40;
                        i++;
                        continue;
                    }
                    else{
                        ans += 90;
                        i++;
                        continue;
                    }
                }
                else if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')){
                    if(s[i+1] == 'D'){
                        ans += 400;
                        i++;
                        continue;
                    }
                    else{
                        ans += 900;
                        i++;
                        continue;
                    }
                }
            }

            ans += mp[s[i]];
        }

        return ans;
    }
};