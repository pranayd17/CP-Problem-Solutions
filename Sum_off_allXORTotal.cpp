class Solution {
public:
    int ans=0;
    void help(vector<int>& arr, int i, int xorr){
        if(i == arr.size()){
            ans += xorr;
            return;
        }
        help(arr, i+1, xorr^arr[i]);
        help(arr, i+1, xorr);
    }
	
    int subsetXORSum(vector<int>& arr) {
       help(arr, 0, 0);
       return ans;
    }
};
