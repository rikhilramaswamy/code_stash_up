typedef unordered_map<int,int> myMap;
typedef pair<int,int> myMap_pair;
typedef vector<int> vi;

class RandomizedSet {
private:
    myMap m1;
    vi v1;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool res = true;
        auto itr = m1.find(val);
        if(itr != m1.end())
            return false;
        
        v1.push_back(val);
        m1.insert(myMap_pair(val, v1.size()-1));
        return true;
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool res = true;
        auto itr = m1.find(val);
        if(itr == m1.end())
            return false;
        
        swap(v1[v1.size()-1], v1[itr->second]);
        int nkey = v1[itr->second];
        auto nitr = m1.find(nkey);
        assert(nitr != m1.end());
        nitr->second = itr->second;
        v1.pop_back();
        m1.erase(val);
        
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int res =-1;
        if(m1.empty())
            return res;
        
        int index = rand() %  m1.size();
        
        assert(index < v1.size());
        return v1[index];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
