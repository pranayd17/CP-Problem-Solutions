class Solution {
public:
	int f(int i,int j,vector<int>& nums){
		if(i>j) return 0;
		int a= nums[i]+ min(f(i+2,j,nums),f(i+1,j-1,nums));
		int b= nums[j]+ min(f(i+1,j-1,nums),f(i,j-2,nums));
		return max(a,b);
	}

	bool predictTheWinner(vector<int>& nums) {
		int n=nums.size();
		int p1=f(0,n-1,nums);  
		int p2=accumulate(nums.begin(),nums.end(),0)-p1;
		return p1>=p2;
	}
};
