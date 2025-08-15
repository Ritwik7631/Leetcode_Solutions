class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        // two arrays: value, limit both of length n

        // all the elements are INACTIVE at start
        // activation can happen in ANY order

        // # current active elements < limit[i] --> activate an inactive element at ind i
        // activate element at ind i --> value[i] + total activation value (sum of value[i] for all activated elements SO FAR)
        // AFTER each activation, # current active elements = x THEN ALL ell elements j with limit[j] <= x BECOME PERMANENTLY inactive

        // I have to get the max total possible given that activation can happen in any order

        // To maximize total, I have to minimize the permanent deactivations is my intuition
        // basically all values in limit whose value is LESS than # current active elements BECOME PERMANENTLY Inactive


        // value = [1 9 1 1 9 9] limit = [2 1 3 2 4 1]
    
        // {limit, val} and then sort by limit in descending order that way we can always activate them because our cae(current active elements)
        // should be less than the limit[number I choose to activate]. By being able to choose more I can increase my total

        map<long long, multiset<long long, greater<long long>>> mp;
        long long n = value.size();
        for(long long i = 0; i < n; i++){
            mp[limit[i]].insert(value[i]);
        }

        long long total = 0;
        long long active = 0;
        long long last_deactive_num = 0;

        for(auto a : mp){
            long long sz = a.second.size();
            auto top = a.second.begin();
            while(active < a.first && top != a.second.end()){
                total += *top;
                active++;
                top++;
            }

            active -= min(active, sz);

        }

        return total;

        /*
            3: 4,2,1
            2: 5
            active = 3 - 3.size() = 0->1
            total = 0+4+2+1+5
            last_deactive_num = 3
        
        */ 
        


    }
};