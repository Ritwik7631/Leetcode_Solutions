class Solution {
public:
    string longestPalindrome(string s) {
        string modified = "^";

        for(auto a : s)
        {
            modified += a;
            modified += '#';
        }

        modified[modified.size()-1] = '$';

        int l = 1;
        int r = 1;

        int n = modified.size();

        vector<int> radius(n, 0);

        for(int i = 1; i < n-1; i++)
        {
            int mirrored_position = l+r-i;

            int dist_to_edge = r-i;

            if(radius[mirrored_position] > dist_to_edge)
            {
                radius[i] = dist_to_edge;
            }
            else
            {
                radius[i] = radius[mirrored_position];
            }

            while(i + radius[i] + 1 < n && i - radius[i] - 1 > 0 && modified[i + radius[i] + 1] == modified[i - radius[i] - 1])
            {
                radius[i]++;
            }

            if(i + radius[i] > r)
            {
                l = i - radius[i];
                r = i + radius[i];
            }
        }

        int max_length = 0;
        int c;
        for(int i = 1; i < n-1; i++)
        {   
            int current_len;
            int cur_r = radius[i];

            if(modified[i] == '#')
            {
                if(radius[i] % 2 == 0)
                {
                    cur_r--;
                }
            }
            else
            {
                if(radius[i] % 2 == 1)
                {
                    cur_r--;
                }
            }

            current_len = cur_r + 1;

            if(current_len >= max_length)
            {
                max_length = current_len;
                c = i;
            }
        }

        cout << max_length << endl;

        int start = c - radius[c];
        int end = c + radius[c];

        string ans = "";

        for(int i = start; i <= end; i++)
        {
            if(modified[i] != '#')
            {
                ans += modified[i];
            }
        }

        return ans;
    }
};