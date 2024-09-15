class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    void DFS(string current, string stop, unordered_map<string, int> &mp)
    {
        temp.push_back(current);

        if(current == stop)
        {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
            temp.pop_back();
            return;
        }

        string dupl = current;

        for(int i = 0; i < current.size(); i++)
        {
            char original = current[i];

            for(char a = 'a'; a <= 'z'; a++)
            {
                current[i] = a;

                if(mp[current] + 1 == mp[dupl])
                {
                    DFS(current, stop, mp);
                }
            }
            current[i] = original;
        }

        temp.pop_back();

        return;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());

        queue<string> q;

        q.push(beginWord);

        st.erase(beginWord);

        unordered_map<string, int> mp;

        mp[beginWord] = 1;

        while(!q.empty() && q.front() != endWord)
        {
            string word = q.front();
            string dupl = word;
            q.pop();

            for(int i = 0; i < word.size(); i++)
            {
                char original = word[i];

                for(char a = 'a'; a <= 'z'; a++)
                {
                    word[i] = a;

                    if(st.count(word) == 1)
                    {
                        st.erase(word);

                        mp[word] = mp[dupl] + 1;

                        q.push(word);
                    }
                }
                word[i] = original;
            }
        }

        DFS(endWord, beginWord, mp);

        return ans;
    }
};