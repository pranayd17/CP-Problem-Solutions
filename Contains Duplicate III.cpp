class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    set<int> window;  //create sliding window of length indexDiff

    for(int i=0; i<nums.size(); i++){
        if(i > indexDiff) window.erase(nums[i-indexDiff-1]);

        auto pos = window.lower_bound(nums[i]-valueDiff);
       //since we are unable to use full comparision : we opt for set (ordered) & lower_bound() which returns a pointer-- pointing to a value which is equal ot greater than our desired value.
        if(pos != window.end() && *pos - nums[i]<= valueDiff) return true;
        
        window.insert(nums[i]);
        //insert the nums values : if its not the answer we looking for future lookup
    }
      return false;  
    }
};
