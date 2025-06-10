/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool level=0;

        while(q.size()>0){
            vector<int> res(q.size());
            int s=q.size();
            for(int i=0;i<s;i++){
                 TreeNode* temp=q.front();
                 q.pop();
                if(level==0){
                    res[i]=temp->val;
                }
                else{
                    res[s-1-i]=temp->val;
                }

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(res);
            level=!level;
        }
        return ans;
    }
};
