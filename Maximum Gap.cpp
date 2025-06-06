class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int p;
        int result=0;
        if(nums.size()<2){
            return 0;
        }
        else{
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            p=nums[i+1]-nums[i];
            result=max(p,result);
        }
     return result;
     }
    }
};
