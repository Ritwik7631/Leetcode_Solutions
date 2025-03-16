#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node* links[26];
    bool flag = false;
    string word = "";

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }

    bool isEnd()
    {
        return flag;
    }

    void setEnd(string& w)
    {
        flag = true;
        word = w;
    }

    Node* get(char ch)
    {
        return links[ch - 'a'];
    }
};

class Solution
{
public:
    Node* root = new Node();

    void InsertWord(Node* root, string& word)
    {
        Node* curr = root;
        for (char c : word)
        {
            if (!curr->containsKey(c))
            {
                curr->put(c, new Node());
            }
            curr = curr->get(c);
        }
        curr->setEnd(word);
    }

    // DFS that marks visited cells, traverses Trie, and collects found words
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis,
             int i, int j, Node* node, unordered_set<string>& result,
             int& foundCount, const int totalWords)
    {
        if (vis[i][j] == 1 || !node->containsKey(board[i][j]))
        {
            return;
        }

        vis[i][j] = 1;
        char c = board[i][j];
        node = node->get(c);

        if (node->isEnd())
        {
            result.insert(node->word);
            node->flag = false;     // no longer a valid end
            node->word.clear();     // clear word to prevent duplicates
            foundCount++;
        }

        // If we've found all words, we can stop exploring further (optional)
        if (foundCount == totalWords)
        {
            vis[i][j] = 0;
            return;
        }

        static vector<int> rdel{1, 0, -1, 0};
        static vector<int> cdel{0, -1, 0, 1};

        for (int d = 0; d < 4; d++)
        {
            int nr = i + rdel[d];
            int nc = j + cdel[d];
            if (nr >= 0 && nr < (int)board.size() &&
                nc >= 0 && nc < (int)board[0].size() &&
                vis[nr][nc] == 0)
            {
                dfs(board, vis, nr, nc, node, result, foundCount, totalWords);
                // After DFS, check if we have found all words
                if (foundCount == totalWords)
                {
                    break;
                }
            }
        }

        vis[i][j] = 0;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        // 1. Build the Trie and track unique words
        unordered_set<string> uniqueWords;
        for (auto &word : words)
        {
            if (!word.empty())
            {
                InsertWord(root, word);
                uniqueWords.insert(word);
            }
        }

        int n = board.size();
        if (n == 0)
        {
            return {};
        }
        int m = board[0].size();

        // 2. Prepare visited matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // 3. We'll store found words in this set
        unordered_set<string> result;

        // 4. Keep track of how many distinct words have been found
        int foundCount = 0;
        int totalWords = (int)uniqueWords.size();

        // 5. DFS from each cell if root has a child for that char
        for (int i = 0; i < n; i++)
        {
            // Outer loop
            for (int j = 0; j < m; j++)
            {
                // Skip if root doesn't have a child for board[i][j]
                if (root->containsKey(board[i][j]))
                {
                    dfs(board, vis, i, j, root, result, foundCount, totalWords);
                    // After DFS, check if we have found all words
                    if (foundCount == totalWords)
                    {
                        break; // break out of inner loop
                    }
                }
            }
            // Check again after the inner loop
            if (foundCount == totalWords)
            {
                break; // break out of outer loop
            }
        }

        // 6. Convert found words to a vector
        vector<string> ans(result.begin(), result.end());
        return ans;
    }
};
