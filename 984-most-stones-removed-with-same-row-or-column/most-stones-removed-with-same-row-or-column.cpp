class Solution {
public:
    void merge(int X, int Y, map<int,int> &parent)
    {
        int upx = findpar(parent, X);
        int upy = findpar(parent, Y);

        if(upx == upy) return;

        parent[upy] = upx;
    }

    int findpar(map<int,int> &parent, int X)
    {
        if(X == parent[X]) return X;

        return parent[X] = findpar(parent, parent[X]);
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxr = INT_MIN;
        int maxc = INT_MIN;
        set<int> nodes;
        
        for(int i = 0; i < n; i++)
        {
            maxr = max(maxr, stones[i][0]);
            maxc = max(maxc, stones[i][1]);
        }

        for(int i = 0; i < n; i++)
        {
            nodes.insert(stones[i][0]);
            nodes.insert(stones[i][1] + maxr + 1);
        }
        int component = nodes.size();

        map<int,int> parent;

        for(int i = 0; i < maxr + maxc + 2; i++)
        {
            if(nodes.count(i)) parent[i] = i;
        }

        // for(auto a : parent)
        // {
        //     cout << a.first << " " << a.second;
        // }
        // cout << endl;
        
        for(int i = 0; i < n; i++)
        {
            int row = stones[i][0];
            int col = stones[i][1] + maxr + 1;

            if(findpar(parent,row) != findpar(parent,col))
            {
                component--;
                merge(row, col, parent);
            } 

            // for(auto a : parent)
            // {
            //     cout << a << " ";
            // }
            // cout << endl;
        }

        return n - component;
    }
};