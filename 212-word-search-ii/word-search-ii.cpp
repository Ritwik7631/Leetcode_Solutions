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
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        unordered_set<string> result;

        int foundCount = 0;
        int totalWords = (int)uniqueWords.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (root->containsKey(board[i][j]))
                {
                    dfs(board, vis, i, j, root, result, foundCount, totalWords);

                    if (foundCount == totalWords) break;
                }
            }

            if (foundCount == totalWords) break;
        }

        vector<string> ans(result.begin(), result.end());
        return ans;
    }
};
