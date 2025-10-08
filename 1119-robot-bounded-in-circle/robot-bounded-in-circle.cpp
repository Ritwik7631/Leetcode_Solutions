class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<int> rdel = {1, 0, -1, 0};
        vector<int> cdel = {0, -1, 0, 1};

        unordered_map<string,int> char_to_int;
        char_to_int["E"] = 0;
        char_to_int["S"] = 1;
        char_to_int["W"] = 2;
        char_to_int["N"] = 3;

        unordered_map<int,string> int_to_char;
        int_to_char[0] = "E";
        int_to_char[1] = "S";
        int_to_char[2] = "W";
        int_to_char[3] = "N";

        string c_dir = "N";

        vector<int> current = {0,0};

        for(auto a : instructions){
            if(a == 'G'){
                current[0] += rdel[char_to_int[c_dir]];
                current[1] += cdel[char_to_int[c_dir]];
            }
            else if(a == 'L'){
                int val = char_to_int[c_dir];
                int new_d = (val - 1 + 4) % 4;
                c_dir = int_to_char[new_d];
            }
            else if(a == 'R'){
                int val = char_to_int[c_dir];
                int new_d = (val + 1) % 4;
                c_dir = int_to_char[new_d];
            }
        }

        if((current[0] == 0 && current[1] == 0) || c_dir != "N") return true;

        return false;
    }
};