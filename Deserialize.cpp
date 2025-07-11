vector<string> Solution::deserialize(string A) {
vector<string> ans ;
int i = 0;
while(i<A.size()){
string word;
while(i<A.size() && A[i]>='a' && A[i]<='z'){
word.push_back(A[i]);
i++;
}
if(word !="")ans.push_back(word);
i++;
}
return ans ;
}
