class Solution {
public:
    int makeStringGood(string s) {
        map<char, int> freq;
        set<char> st;
        for(auto a : s)
        {
            st.insert(a);
            freq[a]++;
        }
        int mx = INT_MIN;

        for(auto a : freq)
        {
            mx = max(mx, a.second);
        }

        int upperbound = 2*mx+1;

        int n = freq.size();

        int ans = INT_MAX;

        for(int target = 0; target <= upperbound; target++)
        {
            // cout << "target: " << target << endl;
            map<char, int> del, ins, del_dec, ins_dec;

            for(auto a : freq)
            {
                if(target < a.second)
                {
                    del[a.first] = abs(target - a.second);
                    ins[a.first] = INT_MAX;
                } 
                else if(target > a.second)
                {
                    ins[a.first] = abs(target - a.second);
                    del[a.first] = a.second;
                } 
                else
                {
                    del[a.first] = 0;
                    ins[a.first] = 0;
                }
            }
            // cout << "ins: " << endl;
            // for(auto a : ins)
            // {
            //     cout << a.first << " " << a.second << endl;
            // }
            // cout << endl;
            // cout << "del: " << endl;
            // for(auto a : del)
            // {
            //     cout << a.first << " " << a.second << endl;
            // }
            // cout << endl;

            auto it = st.begin();

            del_dec[*it] = del[*it];
            ins_dec[*it] = ins[*it];

            auto prev = it;

            it++;

            // cout << *it << endl;

            while(it != st.end())
            {
                auto letter = *it;
                del_dec[letter] = del[letter] + min(del_dec[*prev], ins_dec[*prev]);

                if(ins[letter] != INT_MAX)
                {
                    if(abs(letter - *prev) == 1)
                    {
                        
                        ins_dec[letter] = max(del[*prev], ins[letter]) + (del_dec[*prev] - del[*prev]);//, ins[letter] + ins_dec[*prev]);

                    }
                    else
                    {
                        ins_dec[letter] = ins[letter] +  del_dec[*prev];
                    }

                    if(ins_dec[*prev] != INT_MAX) ins_dec[letter] = min(ins_dec[letter], ins[letter] + ins_dec[*prev]);
                }
                else ins_dec[letter] = INT_MAX;
                
                prev = it;
                it++;
            }

            ans = min({ans, del_dec[*prev], ins_dec[*prev]});

        }
        
        return ans;
    }
};