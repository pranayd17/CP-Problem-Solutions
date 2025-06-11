void get(TreeNode*root,vector<TreeNode*>&v)
 {
     if(!root)return;
     
     v.push_back(root);
     get(root->left,v);
     get(root->right,v);
 }
TreeNode* Solution::flatten(TreeNode* A) {
   
  vector<TreeNode*> v;
  get(A,v);
  v.erase(v.begin());
  TreeNode*root=A;
  for(auto it:v)
  {
      root->right=it;
      root->left=NULL;
      root=root->right;
  }
  return A;
  }
