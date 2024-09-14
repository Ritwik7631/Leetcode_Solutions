class Solution {
public:
    string beginWord;
    unordered_map<string, int> mp;
    vector<string> temp;
    vector<vector<string>> ans;

    void DFS(string currentWord)
    {
        if(currentWord == beginWord)
        {
            temp.push_back(beginWord);
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
            temp.pop_back();

            return;
        }

        temp.push_back(currentWord);

        string prev = currentWord;

        for(int i = 0; i < currentWord.size(); i++)
        {
            char original = currentWord[i];
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                currentWord[i] = ch;

                if(mp[currentWord] != 0 && mp[currentWord] + 1 == mp[prev])
                {
                    DFS(currentWord);
                }
                
            }
            currentWord[i] = original;
        }

        temp.pop_back();

    }

    vector<vector<string>> findLadders(string b, string endWord, vector<string>& wordList) {
        
        beginWord = b;

        mp.clear();
        temp.clear();
        ans.clear();

        mp[beginWord] = 1;

        queue<string> q;
        set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        q.push(beginWord);

        while(!q.empty())
        {
            string word = q.front();
            string prev = word;
            q.pop();

            for(int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if(st.count(word) != 0)
                    {
                        mp[word] = mp[prev] + 1;

                        st.erase(word);

                        q.push(word);
                    }
                }
                word[i] = original;
            }
        }

        DFS(endWord);

        return ans;

    }
};

/*
abc abd aed

abc abd afd

*/