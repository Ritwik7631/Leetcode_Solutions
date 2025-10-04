class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> rdel = {1, 0, -1, 0};
        vector<int> cdel = {0, -1, 0, 1};

        pair<int,int> current(0,0);

        for(auto a : moves){
            if(a == 'R'){
                current.first += rdel[0];
                current.second += cdel[0];
            }
            else if(a == 'D'){
                current.first += rdel[1];
                current.second += cdel[1];
            }
            else if(a == 'L'){
                current.first += rdel[2];
                current.second += cdel[2];
            }
            else if(a == 'U'){
                current.first += rdel[3];
                current.second += cdel[3];
            }

            cout << "current x: " << current.first << " current y: " << current.second << endl;
        }

        return (current.first == 0 && current.second == 0) ? true : false;
    }
};