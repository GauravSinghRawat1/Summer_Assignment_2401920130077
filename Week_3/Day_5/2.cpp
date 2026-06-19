class RecentCounter {
private: queue<int> recentCallsTime;
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        int currtime = t;
        while(recentCallsTime.size()>0 && recentCallsTime.front()<currtime-3000){
            recentCallsTime.pop();
        }
        recentCallsTime.push(t);
        return recentCallsTime.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */