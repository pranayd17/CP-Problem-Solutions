void solve1(TreeNode* A,int x ,int y,map<int,vector<int>>&m){
     if(A==NULL)return;
     
     m[abs(x-y)].push_back(A->val);
     solve1(A->left,x-1,y+1,m);
     solve1(A->right,x+1,y+1,m);
 }
 
 
vector<int> Solution::solve(TreeNode* A) {
    int x = 0;
    int y = 0;
    map<int,vector<int>>m;
    solve1(A,x,y,m);
   
    vector<int>ans;
    for(auto it:m){
        for(auto it1:it.second)ans.push_back(it1);
    }
    return ans;
}
