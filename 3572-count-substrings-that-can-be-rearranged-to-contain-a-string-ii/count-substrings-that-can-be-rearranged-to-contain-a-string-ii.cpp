class Solution {
public:
    bool valid(map<char,int> &freq, map<char,int> &required_freq)
    {
        for(auto a : required_freq)
        {
            if(freq[a.first] < a.second) return false;
        }

        return true;
    }

    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();

        map<char,int> freq, required_freq;

        for(auto a : word2)
        {
            required_freq[a]++;
        }

        int start = 0, end = -1;
        long long ans = 0;
        while(start < n || end < n)
        {
            if(valid(freq, required_freq))
            {
                ans += (n - end);
                freq[word1[start]]--;
                start++;
            }
            else
            {
                if(end < n-1) end++;
                else break;
                freq[word1[end]]++;
            }
        }

        return ans;

        // vector<vector<int>> freq(n, vector<int> (26, 0));

        // vector<int> temp(26, 0);

        // // column is index and row elements is a-z

        // for(int i = 0; i < n; i++)
        // {
        //     temp[word1[i] - 'a']++;

        //     freq[i] = temp;
        // }

        // // for(auto a : freq)
        // // {
        // //     for(auto b : a)
        // //     {
        // //         cout << b << " ";
        // //     }
        // //     cout << endl;
        // // }

        // vector<int> required_freq(26,0);

        // for(int i = 0; i < m; i++)
        // {
        //     required_freq[word2[i] - 'a']++;
        // }

        // // cout << "word2" << endl;
        // // for(auto a : required_freq)
        // // {
        // //     cout << a << " ";
        // // }
        // // cout << endl;

        // long long count = 0;
        // int start = 0;
        // int end = 0;
        // while(start <= end && end < n)
        // {
        //     if(end - start + 1 < m)
        //     {
        //         end++;
        //         continue;
        //     }
        //     // cout << "start: " << start << " end: " << end << endl;
        //     vector<int> a = freq[end];
        //     vector<int> b(26, 0);
        //     if(start - 1 >= 0) b = freq[start-1];

        //     vector<int> diff(26,0);

        //     for(int j = 0; j < 26; j++)
        //     {
        //         diff[j] = a[j] - b[j];
        //     }
        //     // cout << "diff: " << endl; 
        //     // for(auto a : diff) cout << a << " ";
        //     // cout << endl;
        //     // cout << "a: " << endl;
        //     // for(auto x : a) cout << x << " ";
        //     // cout << endl;
        //     // cout << "b: " << endl;
        //     // for(auto x : b) cout << x << " ";
        //     // cout << endl;
    
        //     // cout << endl;
        //     bool flag = true;
        //     for(int i = 0; i < 26; i++)
        //     {
        //         if(diff[i] >= required_freq[i])
        //         {
        //             flag = flag & true;
        //         }
        //         else
        //         {
        //             flag = false;
        //             break;
        //         }
        //     }

        //     if(flag)
        //     {
        //         // cout << "valid" << endl;
        //         count += (n - end);
        //         start++;
        //         end = start + m - 1;
        //     }
        //     else
        //     {
        //         end++;
        //     }
        //     // cout << "count: " << count << endl;
        // }

        // return count;    

    }
};