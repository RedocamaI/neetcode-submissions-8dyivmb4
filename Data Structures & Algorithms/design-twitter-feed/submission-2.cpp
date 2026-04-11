class Twitter {
public:
    unordered_map<int, 
        unordered_map<int, int>
    > followings;
    unordered_map<int,
        priority_queue<pair<int, int>>
    > recentNews;
    int time = 0;

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        recentNews[userId].push({time+1, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> news = 
            recentNews[userId];
        unordered_map<int, int> follows = followings[userId];

        for(auto& followee:follows) {
            int followeeId = followee.second;
            priority_queue<pair<int, int>> fNews = 
                recentNews[followeeId];

            while(!fNews.empty()) {
                news.push(fNews.top());
                fNews.pop();
            }
        }

        vector<int> newsFeed;
        for(int i=0;i<10;i++) {
            if(news.empty())    break;

            int tweetId = news.top().second;
            newsFeed.push_back(tweetId);
            news.pop();
        }

        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)    return;
        followings[followerId][followeeId] = followeeId;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)    return;
        followings[followerId].erase(followeeId);
    }
};
