class Solution {
public:
    void dfs(set<vector<string>>& result, unordered_map<string, vector<string>>& parents, vector<string>& path, string& beginWord, string& current)
    {        
        if(current == beginWord)
        {
            vector<string> completepath = path;
            reverse(completepath.begin(), completepath.end());
            result.insert(completepath);
            return;
        }
        
        for(auto parent : parents[current])
        {
            path.push_back(parent);
            dfs(result, parents, path, beginWord, parent);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()); // visited
  
        if(wordSet.find(endWord) == wordSet.end()) return {};
        
        wordSet.erase(beginWord);
        
        unordered_map<string, vector<string>> parents;
        
        unordered_set<string> current{beginWord};
        
        unordered_set<string> next;
        
        bool found = false;
        
        while(!current.empty() && !found)
        {
            for(auto a : current)
            {
                wordSet.erase(a);
            }
            
            next.clear();
            
            for(auto word : current)
            {
                string temp = word;
            
                for(int i = 0; i < word.size(); i++)
                {
                    char original = temp[i];
                    
                    for(char a = 'a'; a <= 'z'; a++)
                    {
                        temp[i] = a;
                    
                        if(wordSet.count(temp))
                        {
                            next.insert(temp);
                            parents[temp].push_back(word);
                        }
                        
                        if(temp == endWord)
                        {
                            found = true;
                            parents[temp].push_back(word);
                        }
                    }
                    
                    temp[i] = original;
                }
            }
            
            current.swap(next);
        }
        
        set<vector<string>> result;

        vector<vector<string>> temp;

        if(found == false) return temp;
        
        vector<string> path = {endWord};
        dfs(result, parents, path, beginWord, endWord);
        
        vector<vector<string>> ans;

        for(auto a : result) ans.push_back(a);

        return ans;
    }
};