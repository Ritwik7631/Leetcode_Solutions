class AuctionSystem {
public:
    unordered_map<int, unordered_map<int,int>> bids;
    unordered_map<int, priority_queue<pair<long long,int>>> pq;

    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        bids[itemId][userId] = bidAmount;
        pq[itemId].push({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        bids[itemId][userId] = newAmount;
        pq[itemId].push({newAmount, userId});
    }

    void removeBid(int userId, int itemId) {
        bids[itemId].erase(userId);
    }

    int getHighestBidder(int itemId) {
        if (!bids.count(itemId)) return -1;

        auto &heap = pq[itemId];
        auto &mp   = bids[itemId];

        // Remove stale entries
        while (!heap.empty()) {
            auto [amount, userId] = heap.top();
            if (!mp.count(userId)) {     // removed bid — stale
                heap.pop();
                continue;
            }
            if (mp[userId] != amount) {  // outdated bid — stale
                heap.pop();
                continue;
            }
            return userId;               // valid
        }

        return -1;
    }
};
