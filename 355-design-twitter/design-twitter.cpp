class Twitter {
public:
    unordered_map<int, set<pair<int,int>>> mp;
    unordered_map<int, set<int>> following;
    int timer = 0;

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        timer++;
        mp[userId].insert({timer, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        multiset<pair<int,int>> ms(mp[userId].begin(), mp[userId].end());

        for(auto person : following[userId])
        {
            for(auto tweets : mp[person])
            {
                ms.insert(tweets);
            }
        }


        while(ms.size() > 10)
        {
            auto it = ms.begin();
            ms.erase(it);
        }

        vector<int> ans;

        for(auto a : ms)
        {
            ans.push_back(a.second);
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */