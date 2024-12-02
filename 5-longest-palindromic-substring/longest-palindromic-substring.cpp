class Solution {
public:
    string longestPalindrome(string s) {
        string modified = "^#";

        for(auto a : s)
        {
            modified += a;
            modified += '#';
        }

        modified += '$';

        int l = 1;
        int r = 1;
        int n = modified.size();

        vector<int> radius(n, 0);

        for(int i = 1; i < n-1; i++)
        {
            int mirrored_position = l + r - i;

            int dist_to_edge_from_i = r - i;

            if(dist_to_edge_from_i > 0)
            {
                if(radius[mirrored_position] < dist_to_edge_from_i)
                {
                    radius[i] = radius[mirrored_position];
                }
                else
                {
                    radius[i] = dist_to_edge_from_i;
                }
            }
            else
            {
                radius[i] = 0;
            }

            while(i + radius[i] + 1 < n && i - radius[i] - 1 && modified[i + radius[i] + 1] == modified[i - radius[i] - 1])
            {
                radius[i]++;
            }

            if(i + radius[i] > r)
            {
                l = i - radius[i];
                r = i + radius[i];
            } 
        }

        string ans = "";

        int max_length = 0;
        int center_index = 0;
        for (int i = 1; i < n - 1; i++) {
            if (radius[i] > max_length) {
                max_length = radius[i];
                center_index = i;
            }
        }

        int start = (center_index - max_length) / 2;
        return s.substr(start, max_length);

    }
};