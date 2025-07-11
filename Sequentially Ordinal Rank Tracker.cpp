class SORTracker {
public:
    set<pair<int, string>> locations;
    set<pair<int, string>>::iterator currentIterator;

    SORTracker() {
        currentIterator = locations.end();
    }
    
    void add(string name, int score) {
        if(currentIterator != locations.end() && make_pair(-score, name) < *currentIterator)
            locations.insert({-score, name}), currentIterator--;
        else
            locations.insert({-score, name});
    
    }
    
    string get() {
        if(currentIterator == locations.end())
            currentIterator = locations.begin();
        else
            currentIterator++;

        return currentIterator->second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
