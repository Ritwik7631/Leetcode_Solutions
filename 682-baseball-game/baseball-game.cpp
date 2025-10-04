class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;

        int n = operations.size();

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(operations[i] == "C"){
                ans -= record.back();
                record.pop_back();
            }
            else if(operations[i] == "D"){
                int n1 = record.back();
                record.push_back(n1*2);
                ans += (n1*2);
            }
            else if(operations[i] == "+"){
                int n3 = record.back()+record[record.size()-2];;
                record.push_back(n3);
                ans += n3;
            }
            else{
                record.push_back(stoi(operations[i]));
                ans += stoi(operations[i]);
            }   
        }

        return ans;
    }
};