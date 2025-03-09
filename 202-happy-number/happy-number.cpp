class Solution {
public:
    bool isHappy(int n) {
        set<int> visited;

        int x = n;

        while(visited.count(x) == 0 && x != 1)
        {
            visited.insert(x);
            int temp = 0;

            while(x != 0)
            {
                temp += (x%10)*(x%10);
                x = x/10;
            }

            // cout << temp << endl;
            x = temp;
        }

        if(x == 1) return true;

        return false;
    }
};