vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    vector<int> ans;
    if(B > n) return ans;
   
    unordered_map<int, int> mp;
    int count = 0;
    int i=0, j=0;
    while(j<n){
        if(mp[A[j]]==0) count++;
        mp[A[j]]++;
       
         if(j-i+1 == B){
             ans.push_back(count);
             mp[A[i]]--;
             
             if(mp[A[i]] == 0) count--;
             i++;
         }
         j++;
    }
    return ans;
}
