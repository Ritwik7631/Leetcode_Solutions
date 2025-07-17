class Solution {

int dist(vector<int> &a, vector<int> &b){
    return abs(b[0] - a[0]) + abs(b[1] - a[1]);
}

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> min_weight(n, INT_MAX);
        vector<bool> inMST(n, false);

        min_weight[0] = 0;

        int result = 0;


        for(int i = 0; i < n; i++){
            // instead of making use of priority queue I can just loop to find the edge with smallest weight
            int u = -1;
            int best = INT_MAX;

            for(int j = 0; j < n; j++){
                if(!inMST[j] && min_weight[j] < best){
                    best = min_weight[j];
                    u = j;
                }
            }

            inMST[u] = true;

            result += min_weight[u];

            for(int v = 0; v < n; v++){
                if(inMST[v] == false){
                    int w = dist(points[u], points[v]);
                    if(w < min_weight[v]){
                        min_weight[v] = w;
                    }
                }
            }
        }

        return result;
    }
};