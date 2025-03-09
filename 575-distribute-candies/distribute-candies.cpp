class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();

        int target = n/2;

        set<int> candies;

        for(auto a : candyType) candies.insert(a);

        if(candies.size() >= target) return target;

        return candies.size();
    }
};