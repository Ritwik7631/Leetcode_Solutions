struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }

    Node* get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }

};

class WordDictionary {
public:
    Node* root = new Node();
    WordDictionary() {}
    
    void addWord(string word) {
        Node* node = root;

        for(int i = 0; i < word.size(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        return SearchInNode(word, 0, root);
    }

    bool SearchInNode(string word, int i, Node* node)
    {
        if(i == word.size())
        {
            return node->isEnd();
        }

        char ch = word[i];

        if(ch == '.')
        {
            for(int j = 0; j < 26; j++)
            {
                if(node->links[j] != nullptr && SearchInNode(word, i+1, node->links[j])) return true;
            }

            return false;
        }
        else
        {
            if(!node->containsKey(ch)) return false;

            if(SearchInNode(word, i+1, node->get(ch))) return true;

            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */