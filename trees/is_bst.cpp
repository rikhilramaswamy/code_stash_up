/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define invalid -999
class Solution {
public:
    
    bool isValidBST_helper(TreeNode *t, int low, int high){
        if( t == NULL)
            return true;
        
        if(low != invalid && t->val <= low)
            return false;
        
        if(high != invalid && t->val >= high)
            return false;
        
        if(!isValidBST_helper(t->left, low, t->val))
            return false;
        
        if(!isValidBST_helper(t->right, t->val, high))
            return false;
        
        return true;
        
    }
    bool isValidBST(TreeNode* root) {
        
        return isValidBST_helper(root,invalid, invalid );
        
    }
};



class Solution {
public:
    
    bool isValidBST_helper(TreeNode *t, TreeNode *&prev){
        if(t == NULL)
            return true;
        
        if(!isValidBST_helper(t->left, prev))
            return false;
        
        if(prev != NULL && t->val <= prev->val)
            return false;
        
        prev = t;
        
        if(!isValidBST_helper(t->right, prev))
            return false;
        
        return true;
       
        
    }
    bool isValidBST(TreeNode* root) {
        TreeNode * prev = NULL;
        return isValidBST_helper(root,prev);
        
    }
};
