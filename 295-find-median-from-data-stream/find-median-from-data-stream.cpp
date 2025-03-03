#include <queue>
#include <stdexcept>

class MedianFinder {
public:
    std::priority_queue<int, std::vector<int>, std::less<int>> small; // max-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> big;  // min-heap
    
    MedianFinder() {}
    
    void addNum(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
        } else {
            big.push(num);
        }

        if (small.size() > big.size() + 1) {
            big.push(small.top());
            small.pop();
        } else if (big.size() > small.size() + 1) {
            small.push(big.top());
            big.pop();
        }
    }
    
    double findMedian() {
        if (small.empty() && big.empty()) {
            return 0.0;
        }

        if (small.size() > big.size()) {
            return small.top();
        } else if (big.size() > small.size()) {
            return big.top();
        } else {
            return (small.top() + big.top()) / 2.0;
        }
    }
};
