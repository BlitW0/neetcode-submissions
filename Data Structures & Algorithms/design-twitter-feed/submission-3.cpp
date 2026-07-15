class Twitter {
    typedef pair <int, int> pi;

    int time;
    unordered_map <int, vector <pi> > user_tweets;
    unordered_map <int, unordered_set <int> > followees;
public:
    Twitter() : time(0) {}
    
    void postTweet(int userId, int tweetId) {
        user_tweets[userId].emplace_back(++time, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        // {time, tweetId, userId, index}
        // index = pointer for posts of followee with id userId
        using T = tuple<int, int, int, int>;

        priority_queue <T> pq;
        auto pushLast = [&](int u) {
            if (not user_tweets[u].empty()) {
                int idx = user_tweets[u].size() - 1;
                auto [t, id] = user_tweets[u][idx];
                pq.emplace(t, id, u, idx);
            }
        };

        pushLast(userId);
        for (int u : followees[userId])
            pushLast(u);
        
        vector <int> ans;

        while (not pq.empty() and ans.size() < 10) {
            auto [t, id, u, idx] = pq.top(); pq.pop();
            ans.push_back(id);

            // move pointer of followee with most recent tweet to next
            // next = back since latest tweets are pushed back
            if (idx > 0) {
                auto [nt, nid] = user_tweets[u][idx - 1];
                pq.emplace(nt, nid, u, idx - 1);
            }

        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
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