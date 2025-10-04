class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();

        for(int i = n-1; i >= 0; i--){

            if(isalnum(s[i])){
                int count = 0;
                while(i >= 0 && isalnum(s[i])){
                    count++;
                    i--;
                }

                return count;
            }
        }

        return -1;
    }
};