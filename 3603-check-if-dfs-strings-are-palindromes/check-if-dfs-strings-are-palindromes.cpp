class Solution {
public:
    string temp = "";
    map<int, pair<int,int>> mp;
    int timer = 0;
    string g_s;

    vector<int> longestPalindrome(string &s) {
        string modified = "^";

        for(auto a : s)
        {
            modified += a;
            modified += '#';
        }

        modified[modified.size()-1] = '$';

        int l = 1;
        int r = 1;

        int n = modified.size();

        vector<int> radius(n, 0);

        for(int i = 1; i < n-1; i++)
        {
            int mirrored_position = l+r-i;

            int dist_to_edge = r-i;

            if(radius[mirrored_position] > dist_to_edge)
            {
                radius[i] = dist_to_edge;
            }
            else
            {
                radius[i] = radius[mirrored_position];
            }

            while(i + radius[i] + 1 < n && i - radius[i] - 1 > 0 && modified[i + radius[i] + 1] == modified[i - radius[i] - 1])
            {
                radius[i]++;
            }

            if(i + radius[i] > r)
            {
                l = i - radius[i];
                r = i + radius[i];
            }
        }

        // cout << modified << endl;

        return radius;
    }

    void fn(int i, vector<vector<int>>& adj) {

        mp[i].first = timer;

        for (auto a : adj[i]) {
            fn(a, adj);
        }

        mp[i].second = timer;

        timer++;

        temp += g_s[i];

        return;
    }

    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = parent.size();
        g_s = s;

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            int a = i;
            int b = parent[i];
            if (b != -1 && a != b) { 
                adj[b].push_back(a);
            }
        }

        for(int i = 0; i < n; i++) sort(adj[i].begin(), adj[i].end());

        fn(0, adj);

        // cout << "Temp: " << temp << endl;

        // for(auto a : mp)
        // {
            
        //     cout << a.first << " " << a.second.first << " " << a.second.second << endl;
        // }
        // cout << endl;
        

        vector<bool> ans(n, false);

        vector<int> radius = longestPalindrome(temp); 

        // for(auto a : radius)
        // {
        //     cout << a << " ";
        // }

        for(auto a : mp)
        {
            int dfs_call = a.first;

            int start = a.second.first;
            int end = a.second.second;

            if(end-start == 0) ans[dfs_call] = true;
            else
            {
                int converted_start = 2*start + 1;
                int converted_end = 2*end + 1;
                int converted_mid = (converted_start + converted_end)/2;

                if(converted_mid + radius[converted_mid] >= converted_end &&
                    converted_mid - radius[converted_mid] <= converted_start)
                    {
                        ans[dfs_call] = true;
                    }
            }
        }

        return ans; 
    }
};



/*
0 1 2 3 4

0: 3,0
1: 3,1
2: 5,2
3: 3,3
4: 4,4
5: 5,5

dfs(i) start = first child node of i 
       end = i

If all children are unvisited then the first child leaf node becomes your start for 

341520 = ^ a # b # a # a # b # a $
         0 0 0 2 0 1 5 1 0 2 0 0 0 

1. searching for dfs node number in dfs(0) string via map
2. Taking index of that node number in dfs(0) string
3. converting to odd for modified string
4. checking mid element
(((a) (b) a) ((a) b) a) 0->1->3->4->5->2
   3   4  1    5  2  0

KEY: Idea is to check 3->0, then 3->1, then 5->2, ... 5 to 2 is even # of elements so maybe we check radius of l_mid and r_mid

While checking node x the string representing the subtree of node x
should be palindrome

make adj list

dfs(0, string)
{
    we only append to string when node 
    has no more children left to visit

    then we can check if string is palindrome or not

    
}



*/