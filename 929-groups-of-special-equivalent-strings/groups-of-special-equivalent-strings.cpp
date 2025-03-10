class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_map<string,int> mp;

        for(auto word : words)
        {
            multiset<string> total;
            for(int i = 0; i < word.size(); i++)
            {
                if(i%2)
                {
                    string temp = "";
                    temp += word[i];
                    temp += 'o';
                    total.insert(temp);
                }
                else
                {
                    string temp = "";
                    temp += word[i];
                    temp += 'e';
                    total.insert(temp);
                }
            }

            string final = "";

            for(auto a : total) final += a;

            // cout << final << endl;

            mp[final]++;
        }

        return mp.size();
    }
};