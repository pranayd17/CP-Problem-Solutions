#define ll long long
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        if(n<=1) return 1;
        
        for(int i=1;i<n;i++){
            if(complexity[i]<=complexity[0]){
                return 0;
            }
        }
        ll ans=1;
        ll M=1e9+7;
        for(int i=1;i<n;i++){
            ans=(ans*i)%M;
        }
        return ans;
    }
};
