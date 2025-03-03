class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;

        for(auto a : tasks)
        {
            mp[a]++;
        }

        multiset<int, greater<int>> ms;

        for(auto a : mp)
        {
            ms.insert(a.second);
        }

        // for(auto a : ms) cout << a << " ";
        // cout << endl;

        int timer = 0;

        int count = 0;

        queue<pair<int,int>> q;

        while(!ms.empty() || !q.empty())
        {
            timer++;
            count++;

            if(!q.empty() && q.front().second == timer)
            {
                ms.insert(q.front().first);
                q.pop();
            }

            if(!ms.empty())
            {
                int pr = *ms.begin();
                ms.erase(ms.begin());
                pr--;

                if(pr > 0) q.push({pr, timer+n+1});
            }
        }

        return count;
    }
};