class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> target(26, 0);

        for(auto a : p)
        {
            target[a - 'a']++;
        }

        vector<vector<int>> prefix(s.size(), vector<int>(26, 0));

        vector<int> temp(26, 0);

        for(int i = 0; i < s.size(); i++)
        {
            temp[s[i] - 'a']++;
            prefix[i] = temp;
        }

        vector<int> ans;

        int n = p.size();

        for(int i = 0; i+n-1 < s.size(); i++)
        {
            vector<int> diff(26);
            vector<int> a = prefix[i+n-1];
            

            // for(auto b : a) cout << b << " ";
            // cout << endl;
            // for(auto c : b) cout << c << " ";
            // cout << endl;
            // cout << endl;

            

            if(i == 0)
            {
                diff = a;
            }
            else
            {
                vector<int> b = prefix[i-1];
                for(int k = 0; k < 26; k++)
                {
                    diff[k] = a[k] - b[k];
                }
            }

            if(diff == target) ans.push_back(i);
        }

        return ans;
    }
};