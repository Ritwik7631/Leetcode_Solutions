#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // We'll keep track of answers and adjacency as class members
    vector<vector<int>> ans;
    vector<vector<int>> adj;
    
    // Keep track of the minimum frequency sum found so far
    int minLen = INT_MAX;
    
    // DFS for cycle detection
    // vis[u] == 0 => unvisited, 1 => in-progress, 2 => finished
    // Return true if a cycle is found
    bool dfsCycle(int u, vector<int> &freq, vector<int> &vis) {
        if (vis[u] == 1) return true;  // found a cycle
        if (vis[u] == 2) return false; // no cycle from this node
        
        vis[u] = 1; // mark in-progress
        for (int nxt : adj[u]) {
            // Only explore edges if the target letter's freq == 1
            if (freq[nxt] == 1) {
                if (dfsCycle(nxt, freq, vis)) {
                    return true; 
                }
            }
        }
        vis[u] = 2; // mark finished
        return false;
    }
    
    // Check if the current freq assignment is free of cycles 
    // among the letters used exactly once (freq[i] == 1).
    bool feasible(vector<int> &freq) {
        vector<int> vis(26, 0);
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 1 && vis[i] == 0) {
                if (dfsCycle(i, freq, vis)) {
                    return false;  // cycle detected
                }
            }
        }
        return true; // no cycle
    }

    // Backtracking over letter indices [0..25]
    void backtrack(vector<int> &freq, int i) {
        // Once we've assigned freq decisions for all letters:
        if (i == 26) {
            // Check if it is feasible (no cycles)
            if (!feasible(freq)) return;
            
            // Compute total sum of frequencies
            int totalCount = 0;
            for (int x : freq) totalCount += x;
            
            // If smaller than the best so far, update
            if (totalCount < minLen) {
                ans.clear();
                minLen = totalCount;
            }
            // If it matches the best, record it
            if (totalCount == minLen) {
                ans.push_back(freq);
            }
            return;
        }
        
        // Branch A: keep freq[i] as is (0 or 1 or 2)
        backtrack(freq, i + 1);
        
        // Branch B: if freq[i] == 1, try duplicating it => freq[i] = 2
        if (freq[i] == 1) {
            freq[i] = 2;
            backtrack(freq, i + 1);
            freq[i] = 1;  // revert
        }
    }

    vector<vector<int>> supersequences(vector<string> &words) {
        // Build adjacency
        adj.assign(26, {});
        
        // Frequency array for letters
        vector<int> freq(26, 0);
        
        // Mark each used letter with freq=1 and build edges
        for (auto &w : words) {
            int a = w[0] - 'a';
            int b = w[1] - 'a';
            adj[a].push_back(b);
            freq[a] = max(freq[a], 1);
            freq[b] = max(freq[b], 1);
        }
        
        ans.clear();
        minLen = INT_MAX;

        // Do backtracking
        backtrack(freq, 0);

        // 'ans' now contains all frequency arrays with minimal sum
        // that can embed each word (no cycles with freq=1 letters).
        return ans;
    }
};
