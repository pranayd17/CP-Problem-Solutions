class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int count=0,prefixsum=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            count+=mp[prefixsum-k];
            mp[prefixsum]++;
        }
        return count;
    }
};
