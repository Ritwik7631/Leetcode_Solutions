class AuctionSystem {
public:
    unordered_map<int, unordered_map<int,int>> a; // [item][user] = amount;
    unordered_map<int, priority_queue<pair<long long, int>>> pq;
    AuctionSystem() {}
    
    void addBid(int userId, int itemId, int bidAmount) {
        a[itemId][userId] = bidAmount;
        pq[itemId].push({bidAmount, userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        a[itemId][userId] = newAmount;
        pq[itemId].push({newAmount, userId});
    }
    
    void removeBid(int userId, int itemId) {
        a[itemId].erase(userId);
    }
    
    int getHighestBidder(int itemId) {
        if(a[itemId].empty()) return -1;

        auto &heap = pq[itemId];
        auto &mp = a[itemId];

        while(!heap.empty()){
            auto [b, u] = heap.top();
            if(mp.count(u) == 0){
                heap.pop();
                continue;
            }
            else if(b != mp[u]){
                heap.pop();
                continue;
            }
            return u;
        }

        return -1;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */