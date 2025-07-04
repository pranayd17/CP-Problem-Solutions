class Skiplist {
public:
    map<int,int>cnt;
    Skiplist() {
        
    }
    
    bool search(int target) {
        if(cnt[target]>0){
            return true;
        }
        return false;
    }
    
    void add(int num) {
        if(cnt[num]<0){
            cnt[num]=0;
        }
        cnt[num]++;
    }
    
    bool erase(int num) {
        if(cnt[num]>0){
            cnt[num]--;
            return true;
        }
        return false;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
