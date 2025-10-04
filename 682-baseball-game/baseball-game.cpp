class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;

        int n = operations.size();

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(operations[i] == "C"){
                ans -= record[record.size()-1];
                record.pop_back();
            }
            else if(operations[i] == "D"){
                int n1 = record[record.size()-1];
                record.push_back(n1*2);
                ans += (n1*2);
            }
            else if(operations[i] == "+"){
                int n1 = record[record.size()-1];
                int n2 = record[record.size()-1-1];
                int n3 = n1+n2;
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