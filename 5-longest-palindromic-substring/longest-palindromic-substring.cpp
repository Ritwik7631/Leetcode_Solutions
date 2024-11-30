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

        vector<int> radius_centered_at_i(modified.size(), 0);
        
        int l = 1;
        int r = 1;
        int n = modified.size();
        for(int i = 1; i < n; i++)
        {
            // cout << "l: " << l << " r: " << r << " i:" << i << endl;
            // int mirrored_position = l + r - i;

            // cout << mirrored_position << endl;

            radius_centered_at_i[i] = min(r-i, radius_centered_at_i[l+r-i]);
            
            while(i + radius_centered_at_i[i] + 1 < n &&
                  i - radius_centered_at_i[i] - 1 >= 0 &&
                  modified[i + radius_centered_at_i[i] + 1] == modified[i - radius_centered_at_i[i] - 1])
                  {
                        radius_centered_at_i[i]++;
                  }

            int current_l = i - radius_centered_at_i[i];
            int current_r = i + radius_centered_at_i[i];

            if(current_r > r)
            {
                r = current_r;
                l = current_l;
            }

            // for(auto a : radius_centered_at_i)
            // {
            //     cout << a << "  ";
            // }
            // cout << endl;

            // for(auto a : modified)
            // {
            //     cout << a << "  ";
            // }
            // cout << endl;

            // for(int i = 0; i < modified.size(); i++)
            // {
            //     if(i < 10) cout << 0;
            //     cout << i << " ";
            // }
            // cout << endl;
            // cout << "------------------------------" << endl;            
        }

        // radius_centered_at_i[0] = -1;
        // radius_centered_at_i[modified.size()-1] = -1;

        int max_length = 0;
        int start, end;
        int c;

        for(int i = 1; i < radius_centered_at_i.size() - 1; i++)
        {
            int r = radius_centered_at_i[i];

            if(modified[i] == '#')
            {
                if(r%2 == 0) r--;
            }
            else
            {
                if(r%2 == 1) r--;
            }

            int current_length = r + 1;

            if(current_length >= max_length)
            {
                max_length = current_length;
                c = i;
            }
        }

        // for(auto a : radius_centered_at_i)
        // {
        //     cout << a << "  ";
        // }
        // cout << endl;

        start = c - radius_centered_at_i[c];
        end = c + radius_centered_at_i[c];

        // for(auto a : modified)
        // {
        //     cout << a << "  ";
        // }
        // cout << endl;

        // for(int i = 0; i < modified.size(); i++)
        // {
        //     if(i < 10) cout << 0;
        //     cout << i << " ";
        // }
        // cout << endl;

        // cout << "s: " << start << endl;
        // cout << "e: " << end << endl;
        // cout << "c: " << c << endl;

        string ans = "";

        for(int x = start; x <= end; x++)
        {
            if(modified[x] != '#')
            {
                ans += modified[x];
            }
        }

        return ans;
    }
};