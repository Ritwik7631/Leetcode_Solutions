class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());
        int i = 0;
        while(i < n) {
            if(formula[i] == '(') {
                st.push(unordered_map<string, int>());
                i++;
            } else if(formula[i] == ')') {
                i++;
                int multiplier = 0;
                while(i < n && isdigit(formula[i])) {
                    multiplier = multiplier * 10 + (formula[i] - '0');
                    i++;
                }
                if(multiplier == 0) multiplier = 1;
                auto topMap = st.top();
                st.pop();
                for(auto &p : topMap) {
                    st.top()[p.first] += p.second * multiplier;
                }
            } else {
                // Parse an element name.
                string element;
                element.push_back(formula[i++]);
                while(i < n && islower(formula[i])) {
                    element.push_back(formula[i++]);
                }
                int count = 0;
                while(i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }
                if(count == 0) count = 1;
                st.top()[element] += count;
            }
        }
        
        // The final map holds the counts for all elements.
        auto resMap = st.top();
        vector<string> elems;
        for(auto &p : resMap) {
            elems.push_back(p.first);
        }
        sort(elems.begin(), elems.end());
        
        string ans;
        for(auto &e : elems) {
            ans += e;
            if(resMap[e] > 1)
                ans += to_string(resMap[e]);
        }
        return ans;
    }
};
