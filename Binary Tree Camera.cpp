    int minCameraCover(TreeNode* root) {
        auto t = helper(root);
        return min(get<1>(t), get<2>(t));
    }
	
    tuple<int, int, int> helper(TreeNode *root) {
        if (!root) {
            return {0, 0, 1};
        }
        int left_not_covered, left_covered, left_parent_covered;
        tie(left_not_covered, left_covered, left_parent_covered) = helper(root->left);
        int right_not_covered, right_covered, right_parent_covered;
        tie(right_not_covered, right_covered, right_parent_covered) = helper(root->right);
        return {left_covered + right_covered, 
                min(left_not_covered + right_not_covered + 1,
                    min(left_parent_covered + right_covered, left_covered + right_parent_covered)), 
                min(left_not_covered, left_covered) + min(right_not_covered, right_covered) + 1};
    }
