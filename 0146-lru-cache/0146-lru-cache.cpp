typedef pair<int,int> ii; // convenience
class LRUCache {
public:
    // key, (value, frequency)
    unordered_map<int, ii> memo;
    // (key, frequency)
    queue<ii> q;

    int cap;
    LRUCache(int capacity) {
        cap = capacity; // cap > 1
    }
    
    int get(int key) {
        if(memo.find(key) == memo.end()){
            return -1;
        }
        memo[key].second++;
        q.push(ii(key, memo[key].second));
        return memo[key].first;
    }
    
    void put(int key, int value) {
        // check if the key exists
        if(memo.find(key) != memo.end()){
            memo[key].first = value;
            memo[key].second++;
            q.push(ii(key, memo[key].second));
            return; // key exists, update and exit
        }
        // key does not exist. Evict if necessary before adding.
        if(memo.size() == cap){
            // purge q until we get a frequency match
            while(q.front().second != memo[q.front().first].second){
                q.pop();
            }
            ii p = q.front(); q.pop();
            memo.erase(p.first);
        }
        memo[key] = ii(value,1);
        q.push(ii(key, memo[key].second));
    }
};
