class Solution {
public:
    int findpar(int X, vector<int> &parent)
    {
        if(X == parent[X]) return X;

        return parent[X] = findpar(parent[X], parent);
    }

    void join(int X, int Y, vector<int> &parent)
    {
        int upx = findpar(X, parent);
        int upy = findpar(Y, parent);

        if(upx == upy) return;

        parent[upy] = upx;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        int extra = 0;
        int components = n;
        for(auto a : connections)
        {
            int b = a[0];
            int c = a[1];

            int upb = findpar(b, parent);
            int upc = findpar(c, parent);

            if(upb == upc) extra++;
            else components--;

            join(b, c, parent);
        }

        if(extra >= components - 1) return components - 1;
        else return -1;


    }
};