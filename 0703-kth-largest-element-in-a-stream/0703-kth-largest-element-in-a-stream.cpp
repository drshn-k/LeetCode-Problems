class KthLargest {
    multiset<int> m;
    multiset<int>::iterator it = m.end(); // iterator to point to the K'th Largest Element always
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int x:nums){
            m.insert(x);
        }
        it = m.end();
        K=k;
    }
    
    int add(int val) { // time O ( log n ) insertion in multiset
        m.insert(val);
        if(it == m.end()){ //First time adding value
            it = m.end();
            for(int i=0;i<K;i++,it--); // 'it' is made to point to the K'th Largest Element
        }
        else{
            if(val>=*it){
                it++; // moved forward to point to K'th Largest element now
            }
        }
        return *it;
    }
};
