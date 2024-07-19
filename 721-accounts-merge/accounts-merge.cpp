#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findpar(int X, vector<int> &parent) {
        if(X == parent[X]) return X;
        return parent[X] = findpar(parent[X], parent);
    }

    void merge(vector<int> &parent, int X, int Y) {
        int upx = findpar(X, parent);
        int upy = findpar(Y, parent);
        if(upx == upy) return;
        parent[upy] = upx;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> mp1; // map from email to name
        unordered_map<string, int> mp2;    // map from email to index
        unordered_map<int, string> mp3;    // map from index to email

        int k = 1;
        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                if(mp2[accounts[i][j]] > 0) continue;
                mp2[accounts[i][j]] = k;
                mp3[k] = accounts[i][j];
                mp1[accounts[i][j]] = accounts[i][0];
                // cout << "Mapping email " << accounts[i][j] << " to index " << k << " and name " << accounts[i][0] << endl;
                k++;
            }
        }

        vector<int> parents(k);
        for(int i = 1; i < parents.size(); i++) {
            parents[i] = i;
        }

        // cout << "Initial parents array: ";
        for(int i = 1; i < parents.size(); i++) {
            // cout << parents[i] << " ";
        }
        // cout << endl;

        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 2; j < accounts[i].size(); j++) {
                merge(parents, mp2[accounts[i][j]], mp2[accounts[i][j-1]]);
                // cout << "Merging " << accounts[i][j] << " and " << accounts[i][j-1] << endl;
            }
        }

        // cout << "Parents array after merging: ";
        for(int i = 1; i < parents.size(); i++) {
            // cout << parents[i] << " ";
        }
        // cout << endl;

        vector<vector<string>> ans;
        unordered_map<int, vector<string>> mp4;

        for(int i = 1; i < parents.size(); i++) {
            parents[i] = findpar(parents[i], parents);
            mp4[parents[i]].push_back(mp3[i]);
            // cout << "Parent of " << mp3[i] << " is " << parents[i] << endl;
        }

        // cout << "Final parents array after path compression: ";
        for(int i = 1; i < parents.size(); i++) {
            // cout << parents[i] << " ";
        }
        // cout << endl;

        for(auto &a : mp4) {
            vector<string> temp;
            sort(a.second.begin(), a.second.end());
            temp = a.second;
            temp.insert(temp.begin(), mp1[mp3[a.first]]);
            ans.push_back(temp);
            // cout << "Merged account for parent " << a.first << " is: ";
            for(auto &s : temp) {
                // cout << s << " ";
            }
            // cout << endl;
        }

        return ans;
    }
};