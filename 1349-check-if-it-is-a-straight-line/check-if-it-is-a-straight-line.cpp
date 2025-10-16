class Solution {
public:
    double calc_slope(vector<int> a1, vector<int> a2){
        if (a2[0] == a1[0]) return DBL_MAX;
        return (double)(a2[1] - a1[1]) / (a2[0] - a1[0]);
    }

    double calc_y_int(double m, vector<int> a){
        if(m == DBL_MAX) return DBL_MAX;
        return a[1] - (m*a[0]);
    }

    bool valid(double m, double b, int x, int y){
        if(m == DBL_MAX) return x == b;
        return y == (m*x) + b;
    }

    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();

        double slope = calc_slope(coordinates[0], coordinates[1]);

        double y_int;
        
        if(slope == DBL_MAX) y_int = coordinates[0][0];
        else y_int = calc_y_int(slope, coordinates[0]);

        for(auto a : coordinates){
            if(!valid(slope, y_int, a[0], a[1])) return false; 
        }

        return true;
    }
};