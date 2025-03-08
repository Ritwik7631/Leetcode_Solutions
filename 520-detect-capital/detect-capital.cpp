class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag = true;
        for(auto a : word)
        {
            if(!isupper(a))
            {
                flag = false;
                break;
            }
        }

        if(flag) return true;

        flag = true;

        for(auto a : word)
        {
            if(isupper(a))
            {
                flag = false;
                break;
            }
        }

        if(flag) return true;

        flag = true;

        for(int i = 0; i < word.size(); i++)
        {
            if(i == 0)
            {
                if(!isupper(word[i]))
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                if(isupper(word[i]))
                {
                    flag = false;
                    break;
                }
            }
        }

        if(flag) return true;

        return false;
    }
};