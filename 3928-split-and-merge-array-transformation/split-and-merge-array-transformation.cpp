class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if(nums1 == nums2) return 0;

        int n = nums1.size();

        queue<vector<int>> q;
        map<vector<int>, int> dist;

        q.push(nums1);
        dist[nums1] = 0;

        while(!q.empty()){
            vector<int> cur = q.front();
            q.pop();
            int d = dist[cur];

            for(int l = 0; l < n; l++){
                for(int r = l; r < n; r++){
                    vector<int> block(cur.begin() + l, cur.begin() + r + 1);
                    vector<int> rest;
                    for(int i = 0; i < l; i++) rest.push_back(cur[i]);
                    for(int i = r+1; i < n; i++) rest.push_back(cur[i]);

                    for(int k = 0; k <= (int)rest.size(); k++){
                        vector<int> nxt;
                        
                        nxt.insert(nxt.end(), rest.begin(), rest.begin()+k);
                        nxt.insert(nxt.end(), block.begin(), block.end());
                        nxt.insert(nxt.end(), rest.begin()+k, rest.end());

                        if(!dist.count(nxt)){
                            dist[nxt] = d + 1;
                            if(nxt == nums2) return d+1;
                            q.push(nxt);
                        }
                    }
                }
            }
        }

        return -1;
    }
};