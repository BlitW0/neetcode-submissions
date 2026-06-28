class Twitter {
public:
    typedef pair <int, int> pii;

    Twitter() {
        tweetIdx = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        createUserIfNotFound(userId);
        userTweets[userId].push_back( {tweetIdx++, tweetId} );
    }
    
    vector<int> getNewsFeed(int userId) {
        if (!userExists(userId))
            return vector <int> ();
        
        priority_queue <pii, vector <pii>, greater <pii> > allPosts;
        
        // User's own tweets
        for (pii tweet : userTweets[userId]) {
            allPosts.push(tweet);
            if (allPosts.size() > 10)
                allPosts.pop();
        }
        // Tweets from user's following
        for (int followingId : userFollowing[userId])
            for (pii tweet : userTweets[followingId]) {
                allPosts.push(tweet);
                if (allPosts.size() > 10)
                    allPosts.pop();
            }
        
        vector <int> newsFeed;
        while (!allPosts.empty()) {
            newsFeed.push_back(allPosts.top().second);
            allPosts.pop();
        }
        reverse(newsFeed.begin(), newsFeed.end());

        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        
        createUserIfNotFound(followerId);
        createUserIfNotFound(followeeId);

        vector <int> &followers = userFollowers[followeeId];
        vector <int> &following = userFollowing[followerId];

        auto it = find(followers.begin(), followers.end(), followerId);
        if (it == followers.end())
            followers.push_back(followerId);
        
        it = find(following.begin(), following.end(), followeeId);
        if (it == following.end())
            following.push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (!userExists(followerId) || !userExists(followeeId))
            return;
        
        vector <int> &followers = userFollowers[followeeId];
        vector <int> &following = userFollowing[followerId];
        
        auto it = find(followers.begin(), followers.end(), followerId);
        if (it != followers.end())
            followers.erase(it);
        
        it = find(following.begin(), following.end(), followeeId);
        if (it != following.end())
            following.erase(it);
    }

private:
    int tweetIdx;
    unordered_map <int, vector <int> > userFollowers, userFollowing;
    unordered_map <int, vector <pii> > userTweets;

    bool userExists(int userId) {
        return userFollowers.find(userId) != userFollowers.end() &&
                userFollowing.find(userId) != userFollowing.end() &&
                 userTweets.find(userId) != userTweets.end();
    }

    void createUserIfNotFound(int userId) {
        if (!userExists(userId)) {
            userFollowers[userId] = vector <int> ();
            userFollowing[userId] = vector <int> ();
            userTweets[userId] = vector <pii> ();
        }
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