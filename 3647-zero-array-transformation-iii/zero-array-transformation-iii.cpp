class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        multiset<int, greater<int>> maxHeap; // We are storing queries that affect i but are not used yet
        multiset<int> minHeap; // We are storing queries that are activated for num[i]
        sort(queries.begin(), queries.end()); // sorting to make sure that we encounter starting points in increasing order
        int n = nums.size();
        int j = 0; // keeping track of which query is next to process

        for(int i = 0; i < n; i++)
        {
            // cout << "nums[i]: " << nums[i] << endl;
            // The potential queries starting at i are stored in Max Heap
            while(j < queries.size() && queries[j][0] == i)
            {
                maxHeap.insert(queries[j][1]);
                j++;
            }
            // cout << "MaxHeap: " << endl;
            // for(auto a : maxHeap)
            // {
            //     cout << a << " ";
            // }
            // cout << endl;

            nums[i] -= minHeap.size(); // the effect of activated queries

            // cout << "remaining: " << nums[i] << endl;

            // If nums[i] > 0 then you can start using potential queries from maxHeap and R must be >= i
            while(nums[i] > 0 && maxHeap.size() > 0 && *maxHeap.begin() >= i)
            {
                nums[i]--;
                minHeap.insert(*maxHeap.begin());
                maxHeap.erase(maxHeap.begin());
            }
            // cout << "MaxHeap AFTER: " << endl;
            // for(auto a : maxHeap)
            // {
            //     cout << a << " ";
            // }
            // cout << endl;

            if(nums[i] > 0) return -1;

            // deactivation of activated queries ending at or before i
            while(minHeap.size() > 0 && *minHeap.begin() <= i)
            {
                minHeap.erase(minHeap.begin());
            }

            // cout << "MinHeap AFTER: " << endl;
            // for(auto a : minHeap)
            // {
            //     cout << a << " ";
            // }
            // cout << endl;
        }

        return maxHeap.size();
    }
};