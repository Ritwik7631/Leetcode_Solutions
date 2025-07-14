class Solution {
public:
    int dist(vector<int> &a, vector<int> &b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> min_weight(n, 1e9);
        vector<int> parent(n, -1);
        vector<bool> inMST(n, false);

        min_weight[0] = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            int u = -1;

            for(int j = 0; j < n; j++){
                if(!inMST[j] && (u == -1 || min_weight[j] < min_weight[u])){
                    u = j;
                }
            }

            inMST[u] = true;
            ans += min_weight[u];

            for(int v = 0; v < n; v++){
                if(!inMST[v]){
                    int w = dist(points[u], points[v]);
                    if(w < min_weight[v]){
                        min_weight[v] = w;
                        parent[v] = u;
                    }
                }
            }
        }

        return ans;
    }
};