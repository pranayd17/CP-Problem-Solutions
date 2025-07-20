int Solution::highestScore(vector<vector<string> > &A) {
    unordered_map<string,int> mp;
    unordered_map<string,int> mp1;
    int n = A.size();
    for(int i=0;i<n;i++){
        mp[A[i][0]]+= stoi(A[i][1]);
        mp1[A[i][0]]++;
    }
    int ans=0;
    for(auto it: mp){
        int val = mp1[it.first];
        ans = max(ans,it.second/val);
    }  
    return ans;
}
