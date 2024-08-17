class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        vector<int> temp;

        for (int i = 0; i < n; i++) {
            // If the window size is k, push the appropriate result and slide the window
            if (temp.size() == k) {
                result.push_back(temp.back());
                temp.erase(temp.begin());
            }

            // Check if the current number can be added to the temp (window)
            if (temp.empty() || nums[i] == temp.back() + 1) {
                temp.push_back(nums[i]);
            } else {
                // If not consecutive, clear the window and start fresh
                temp.clear();
                temp.push_back(nums[i]);
            }

            // If the window is full and elements are consecutive, push the max element
            if (temp.size() == k) {
                result.push_back(temp.back());
                temp.erase(temp.begin());
            } else if (temp.size() < k && i >= k - 1) {
                // If the window is not full and we're past the initial elements, push -1
                result.push_back(-1);
            }
        }

        return result;
    }
};

