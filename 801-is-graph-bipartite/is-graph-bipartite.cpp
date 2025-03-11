class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> colors(n, -1);

        for(int i = 0; i < n; i++)
        {
            // if uncolored
            if(colors[i] == -1)
            {
                queue<int> q;
                q.push(i);
                colors[i] = 0;

                while(!q.empty())
                {
                    int front = q.front();
                    q.pop();

                    for(auto a : graph[front])
                    {
                        if(colors[a] == -1)
                        {
                            colors[a] = !colors[front];
                            q.push(a);
                        }
                        else
                        {
                            if(colors[a] == colors[front])
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};