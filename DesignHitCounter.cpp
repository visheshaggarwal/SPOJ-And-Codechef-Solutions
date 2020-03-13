class HitCounter {
    list<long> l;
    long cnt;
public:
    /// Initialize your data structure here.
    HitCounter() {
        cnt = 0;
    }

    /* Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        l.push_back(timestamp);
        cnt++;
        while(l.size()>0 && timestamp - 300 >= l.front())
        {
            l.pop_front();
            cnt--;
        }
    }

    /* Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(l.size()>0  && timestamp - 300 >= l.front())
        {
            l.pop_front();
            cnt--;
        }
        return cnt;
    }
};

/*
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
