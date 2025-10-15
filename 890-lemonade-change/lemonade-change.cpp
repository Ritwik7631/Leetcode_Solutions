#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        int fives = 0;
        int tens = 0;

        for(int i = 0; i < n; i++){
            if(bills[i] == 5){
                fives++;
            }
            else if(bills[i] == 10){
                tens++;

                if(fives >= 1) {
                    fives--;
                } else {
                    return false;
                }
            }
            else {
                if(tens >= 1 && fives >= 1){
                    tens--;
                    fives--;
                }
                else if(fives >= 3){
                    fives -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};
