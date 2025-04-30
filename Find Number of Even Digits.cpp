class Solution {
public:

    int getdigit(int n){
        int c=0;
        while(n){
            c++;
            n/=10;
        }
        return c;
    }

    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int x=getdigit(nums[i]);
            if(x%2==0) ans++;
        }
        return ans;
    }
};
