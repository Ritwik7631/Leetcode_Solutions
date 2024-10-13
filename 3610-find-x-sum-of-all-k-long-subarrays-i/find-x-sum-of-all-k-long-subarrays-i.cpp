class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1, 0);

        for (int i = 0; i <= n - k; i++) {
            long long count = 0;
            int start = i;
            int end = i + k - 1;

            unordered_map<int, int> window_freq;
            for (int j = start; j <= end; ++j) {
                window_freq[nums[j]]++;
            }

            vector<pair<int, int>> freq_vec;
            for (auto& wf : window_freq) {
                freq_vec.push_back({wf.second, wf.first});
            }

            sort(freq_vec.begin(), freq_vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.first != b.first)
                    return a.first > b.first; // Higher frequency first
                else
                    return a.second > b.second; // Higher value first in case of tie
            });

            // Keep track of the top x elements
            unordered_set<int> top_elements;
            for (int idx = 0; idx < x && idx < freq_vec.size(); ++idx) {
                top_elements.insert(freq_vec[idx].second);
            }

            // Calculate the sum of the top elements in the current window
            for (int j = start; j <= end; ++j) {
                if (top_elements.count(nums[j])) {
                    count += nums[j];
                }
            }

            ans[i] = count;
        }

        return ans;

    }
};