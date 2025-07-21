vector<vector<int> > Solution::anagrams(const vector<string> &A) {
map<vector<int>,vector<int>>mp;
for(int i=0;i<A.size();i++){
vector<int>temp(26,0);
for(int j=0;j<A[i].size();j++){
temp[A[i][j]-'a']++;
}
mp[temp].push_back(i+1);
}
vector<vector<int>> vec;
for(auto it:mp){
vec.push_back(it.second);
}
return vec;
}
