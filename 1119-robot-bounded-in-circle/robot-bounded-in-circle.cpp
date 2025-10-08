class Solution {
public:
    bool isRobotBounded(string instructions) {
        // dir 0=N, 1=E, 2=S, 3=W

        vector<int> rdel = {0, 1, 0, -1};
        vector<int> cdel = {1, 0, -1, 0};

        int dir = 0;

        int n = instructions.size();

        vector<int> current = {0,0};

        for(int i = 0; i < n; i++){
            if(instructions[i] == 'G'){
                current[0] += rdel[dir];
                current[1] += cdel[dir];
            }
            else if(instructions[i] == 'L'){
                dir = (dir - 1 + 4) % 4;
            }
            else{
                dir = (dir + 1) % 4;
            }
        }

        if(dir != 0 || (current[0] == 0 && current[1] == 0)) return true;

        return false;
    }
};