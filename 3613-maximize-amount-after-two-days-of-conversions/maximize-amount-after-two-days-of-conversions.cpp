class Solution {
public:
    // # the currencys are nodes and the rates are edges
    // # initial currency is given
    // # you can only keep going back and forth unlimited times if they are in the same day
    // # no greedy choices to make just construct graph and then go through every possibility and record max at each step
    // # thinking about keeping each graph separate and maximize each and then return the sum of both

    // double mx1 = 0;
    // double mx2 = 0;
    // map<string, vector<pair<string,double>>> adj1;
    // map<string, vector<pair<string,double>>> adj2;

    // void dfs1(string node, string parent, map<string, vector<pair<string,double>>>& adj1, double current)
    // {
    //     for(auto a : adj1[node])
    //     {
    //         if(a.first != parent)
    //         {
    //             dfs1(a.first, node, adj1, current * a.second);
    //             mx1 = max(mx1, current * a.second);
    //         }
    //     }
    //     return;
    // }

    // void dfs2(string node, string parent, map<string, vector<pair<string,double>>>& adj2, double current)
    // {
    //     for(auto a : adj2[node])
    //     {
    //         if(a.first != parent)
    //         {
    //             dfs2(a.first, node, adj2, current * a.second);
    //             mx2 = max(mx2, current * a.second);
    //         }
    //     }
    //     return;
    // }

    void dfs(string node, string parent, map<string, vector<pair<string,double>>> &adj1, double current, map<string, double> &mx1)
    {
        for(auto a : adj1[node])
        {
            if(a.first != parent)
            {
                mx1[a.first] = max(mx1[a.first], current*a.second);
                dfs(a.first, node, adj1, current*a.second, mx1);
            }
        }

        return;
    }

    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {

    //     for(int i = 0; i < pairs1.size(); i++)
    //     {
    //         double inverse = 1.0 / rates1[i];
    //         adj1[pairs1[i][0]].emplace_back(pairs1[i][1], rates1[i]);
    //         adj1[pairs1[i][1]].emplace_back(pairs1[i][0], inverse);
    //     }

    //     for(int i = 0; i < pairs2.size(); i++)
    //     {
    //         double inverse = 1.0 / rates2[i];
    //         adj2[pairs2[i][0]].emplace_back(pairs2[i][1], rates2[i]);
    //         adj2[pairs2[i][1]].emplace_back(pairs2[i][0], inverse);
    //     }

    //     double current = 1.0;

    //     dfs1(initialCurrency, "", adj1, current);

    //     map<string, vector<pair<string,double>>> tempAdj2 = adj2;
    //     for(auto& adj : tempAdj2)
    //     {
    //         for(auto& edge : adj.second)
    //         {
    //             edge.second *= mx1; // Incorporating Day 1 results
    //         }
    //     }

    //     dfs2(initialCurrency, "", tempAdj2, mx1);

    //     if(mx1 < 1.0) mx1 = 0;
    //     if(mx2 < 1.0) mx2 = 0;

    //     return mx2; // Return maximum after Day 2

        map<string, vector<pair<string,double>>> adj1;
        map<string, vector<pair<string,double>>> adj2;
        set<string> currencies1;
        set<string> currencies2;

        for(int i = 0; i < pairs1.size(); i++)
        {
            double inverse = 1.0 / rates1[i];
            adj1[pairs1[i][0]].emplace_back(pairs1[i][1], rates1[i]);
            adj1[pairs1[i][1]].emplace_back(pairs1[i][0], inverse);
            currencies1.insert(pairs1[i][1]);
            currencies1.insert(pairs1[i][0]);
        }

        for(int i = 0; i < pairs2.size(); i++)
        {
            double inverse = 1.0 / rates2[i];
            adj2[pairs2[i][0]].emplace_back(pairs2[i][1], rates2[i]);
            adj2[pairs2[i][1]].emplace_back(pairs2[i][0], inverse);
            currencies2.insert(pairs2[i][0]);
            currencies2.insert(pairs2[i][1]);
        }

        map<string, double> mx1;
        map<string, double> mx2;
        double current = 1.0;

        dfs(initialCurrency, "-1", adj1, current, mx1);

        mx2 = mx1;

        for(auto a : currencies1)
        {
            if(currencies2.count(a))
            {
                dfs(a, "-1", adj2, mx1[a], mx2);
            }
        }

        if(mx2[initialCurrency] == 0) return 1.0;

        return max(mx2[initialCurrency], 1.0);





    }
};
