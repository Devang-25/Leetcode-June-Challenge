class RandomizedSet {
public:
    map<int, int> m;
    vector<int> v;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val)!=m.end())
            return false;
        int idx = v.size();
        m[val] = idx;
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;
        
        int last = v.back();
        int i = m[val];
        swap(v[i], v[v.size()-1]);
        m[last] = i;
        
        m.erase(val);
        v.erase(v.end()-1);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int pos = rand() % v.size();
        
        return v[pos];
    }
};

 