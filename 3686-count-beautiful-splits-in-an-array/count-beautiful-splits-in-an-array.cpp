class Solution {
public:
    vector<long long> prefixhash; // prefixhash[i] represents the hash from 0 to i
    vector<long long> basepower; // basepower[i] represents the 
    int mod = 1e9+7;
    void fn(vector<int>& nums)
    {
        int n = nums.size();

        prefixhash.resize(n+1, 0);
        basepower.resize(n+1, 1);
        int base = 57;
        // we populate basepower in n time
        for(int i = 1; i <= n; i++)
        {
            basepower[i] = (basepower[i-1] * base) % mod;
        }
        // we populate prefixhash in n time
        for(int i = 0; i < n; i++)
        {
            prefixhash[i+1] = (prefixhash[i] + (nums[i]*basepower[i])%mod)%mod;
        }
        
    }

    int hash(int start, int len)
    {
        return (prefixhash[start+len] - (prefixhash[start]*basepower[len])%mod + mod)%mod;
    }

    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        fn(nums);

        // for(auto a : prefixhash)
        // {
        //     cout << a << " ";
        // }
        // cout << endl;

        int count = 0;

        for(int i = 1; i <= n-2; i++)
        {
            for(int j = i+1; j <= n-1; j++)
            {
                bool cond1 = false, cond2 = false;

                if(j-i >= i - 0)
                {
                    int h1 = hash(0, i);
                    int h2 = hash(i, i);

                    // cout << "h1: " << h1 << " " << " h2: " << h2 << endl;

                    if(h1 == h2) cond1 = true;
                }

                if(n-j >= j-i)
                {
                    int h3 = hash(i, j-i);
                    int h4 = hash(j, j-i);

                    // cout << "h3: " << h3 << " " << " h4: " << h4 << endl;

                    if(h3 == h4) cond2 = true;
                }

                if(cond1 || cond2) count++;
            }
        }

        return count;
    }
};