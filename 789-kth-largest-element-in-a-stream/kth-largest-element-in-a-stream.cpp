#include <set>
#include <vector>
using namespace std;

class KthLargest {
private:
    int k;
    multiset<int> ms;
    
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        ms.insert(val);
        if (ms.size() > k) {
            ms.erase(ms.begin());
        }
        return *ms.begin();
    }
};
