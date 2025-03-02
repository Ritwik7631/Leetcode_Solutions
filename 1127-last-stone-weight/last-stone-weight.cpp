class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int, greater<int>> ms;

        for(auto a : stones) ms.insert(a);

        while(ms.size() >= 2)
        {
            int y = *ms.begin();
            ms.erase(ms.begin());
            int x = *ms.begin();
            ms.erase(ms.begin());

            if(y == x) continue;

            ms.insert(y-x);
        }

        if(ms.size() == 0) return 0;

        return *ms.begin();


    }
};