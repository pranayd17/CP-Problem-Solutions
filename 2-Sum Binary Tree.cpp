// Logic :
// Use map to store all elements while recursing through tree
// Now, check if a pair exist using nLogN simply.

void recurse(TreeNode* root,  map<int, int>&m){
    if(root==NULL) return;
    m[root->val]++;
    recurse(root->left, m);
    recurse(root->right, m);
}
int Solution::t2Sum(TreeNode* A, int B) {
    map<int, int>m;
    recurse(A, m);
    for(auto it : m){
        if(m.find(B-it.first)!=m.end()){
            if(it.first == B-it.first){
                if(m[it.first]>1){
                    return 1 ;
                }
            }else{
                return 1;
            }
        }
    }
    return 0;
}
