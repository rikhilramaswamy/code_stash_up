class Solution {
public:
    int diameterOfBinaryTree_helper(TreeNode *t, int *ht){
        if ( t == NULL){
            (*ht) = -1;
            return 0;
        }
        
        int lh = 0;
        int left_diag = diameterOfBinaryTree_helper(t->left, &lh);
        
        int rh = 0;
        int right_diag = diameterOfBinaryTree_helper(t->right, &rh);
        int temp_res = max(left_diag, right_diag);
        
        (*ht) = max(lh, rh) +1;
        
        // diagonal via current root
        // you will get lh and rh which are height of left and right children
        // however, current node is at a distance of 1 from left child 
        // and at a distance of 1 from right child; 
        // so to calculate the diameter along the current node : lh + rh + 2
        int curr_diag = lh + rh +2;
        return max(curr_diag,temp_res);    
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ht = 0;
        return diameterOfBinaryTree_helper(root, &ht);
    }
};
