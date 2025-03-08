class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        int mn = INT_MAX;
        string shortest;
        for(auto a : strs)
        {
            if(a.size() < mn)
            {
                mn = a.size();
                shortest = a;
            }
        }
        
        for(int i = 0; i < mn; i++)
        {
            char h = shortest[i];
            bool flag = true;
            for(int j = 0; j < strs.size(); j++)
            {
                if(strs[j][i] != h)
                {
                    return shortest.substr(0,i);
                }

            }
        }

        return shortest;
    }
};