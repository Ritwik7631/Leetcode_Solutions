#include <string>
#include <unordered_map>
#include <stack>
#include <map>
#include <cctype>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        formula = "(" + formula + ")";
        unordered_map<string, int> r;
        stack<map<string, int>> s;
        int i = 0, start;
        string element;
        int count;

        map<string, int> sent;
        s.push(sent);

        while (i < formula.size()) {
            if (isupper(formula[i])) {
                start = i;
                i++;
                while (i < formula.size() && islower(formula[i])) {
                    i++;
                }
                element = formula.substr(start, i - start);
                count = 0;
                if (i < formula.size() && isdigit(formula[i])) {
                    while (i < formula.size() && isdigit(formula[i])) {
                        count = count * 10 + (formula[i] - '0');
                        i++;
                    }
                } else {
                    count = 1;
                }
                s.top()[element] += count;
            } else if (formula[i] == '(') {
                map<string, int> empty;
                s.push(empty);
                i++;
            } else if (formula[i] == ')') {
                i++;
                count = 0;
                if (i < formula.size() && isdigit(formula[i])) {
                    while (i < formula.size() && isdigit(formula[i])) {
                        count = count * 10 + (formula[i] - '0');
                        i++;
                    }
                } else {
                    count = 1;
                }
                map<string, int> top = s.top();
                s.pop();
                for (auto kv = top.begin(); kv != top.end(); kv++) {
                    s.top()[kv->first] += kv->second * count;
                }
            }
        }

        string res = "";
        map<string, int> finalResult = s.top();
        for (auto kv = finalResult.begin(); kv != finalResult.end(); kv++) {
            res += kv->first;
            if (kv->second > 1) {
                res += to_string(kv->second);
            }
        }

        return res;
    }
};
