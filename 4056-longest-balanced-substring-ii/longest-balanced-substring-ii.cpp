class Solution {
public:
    int two(string& s, char a, char b){
        int n = s.size();

        int ans = 0;

        int cur = 0;

        unordered_map<int,int> last_seen;
        last_seen[0] = -1;

        for(int i = 0; i < n; i++){
            if(s[i] == a){
                cur++;
            }
            else if(s[i] == b){
                cur--;
            }
            else{
                cur = 0;
                last_seen.clear();
                last_seen[0] = i;
                continue;
            }

            if(!last_seen.count(cur)){
                last_seen[cur] = i;
            }
            else{
                ans = max(ans, i - last_seen[cur]);
            }
        }

        return ans;
    }

    int longestBalanced(string s) {
        int n = s.size();

        int ans = 0;

        int streak = 0;
        char cur = '1';

        for(int i = 0; i < n; i++){
            if(s[i] == cur){
                streak++;
            }
            else{
                cur = s[i];
                streak = 1;
            }

            ans = max(ans, streak);
        }

        ans = max(ans, two(s, 'a', 'b'));
        ans = max(ans, two(s, 'a', 'c'));
        ans = max(ans, two(s, 'b', 'c'));

        int ab = 0;
        int ac = 0;

        unordered_map<string,int> last_seen;

        last_seen["0#0"] = -1;

        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                ab += 1;
                ac += 1;
            }
            else if(s[i] == 'b'){
                ab -= 1;
            }
            else{
                ac -= 1;
            }

            string state = to_string(ab) + "#" + to_string(ac);

            if(!last_seen.count(state)){
                last_seen[state] = i;
            }
            else{
                ans = max(ans, i - last_seen[state]);
            }
        }

        return ans;

    }
};