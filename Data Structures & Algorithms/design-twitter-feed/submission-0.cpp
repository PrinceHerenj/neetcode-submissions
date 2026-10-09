class Twitter {
public:
    unordered_map<int, unordered_set<int>> follower_set;
    unordered_map<int, vector<pair<int, int>>> user_posts;
    int timer = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        user_posts[userId].push_back({++timer, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<tuple<int, int, int, int>> maxHeap;
        follower_set[userId].insert(userId);
        for (int followeeId: follower_set[userId]) {
            if (user_posts.contains(followeeId)) {
                int lastIndex = user_posts[followeeId].size() - 1;
                auto [time, tweetId] = user_posts[followeeId][lastIndex];
                maxHeap.push({time, tweetId, followeeId, lastIndex - 1});
            }
        }

        while (!maxHeap.empty() and res.size() < 10) {
            auto [time, tweetId, followeeId, lastIndex] = maxHeap.top();
            maxHeap.pop();
            res.push_back(tweetId);

            if (lastIndex >= 0) {
                auto [time, tweetId] = user_posts[followeeId][lastIndex];
                maxHeap.push({time, tweetId, followeeId, lastIndex - 1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follower_set[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower_set[followerId].erase(followeeId);
    }
};
