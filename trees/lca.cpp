/*
 * Complete the function below.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
       /* LCA of a binary tree using percolate up algo*/
	/* assumption: both search nodes are for sure present in the tree */ 
	TreeNode* lowestCommonAncestor_helper( TreeNode *t, TreeNode *p, TreeNode*q){
        if( t == NULL)
            return NULL;
        
        if(t->val == p->val || t->val == q->val)
            return t;
        
        TreeNode *left = lowestCommonAncestor_helper(t->left, p, q);
        TreeNode *right = lowestCommonAncestor_helper(t->right, p, q);
        
        if(left && right){
            return t;
        } else if(left)
            return left;
        else
            return right;
  
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return lowestCommonAncestor_helper(root, p, q);
        
    }
};

/* RKs N-ary tree Algo: */
/* this is based on COUNTING nodes logic */
/* this algo works for binary tree also 
* and EVen if the search nodes are not available */
 pair<Tree *, int> lca(Tree *node, unordered_set <int> & myset) {
 int total =0;
 for (auto ch in t->children) {
          [n, count] = lca(ch, myset);
          if( count == myset.size())
                  return n, count;
           total += count;
   }
     if(total == myset.size())
           return {node, total}

      if (node->val in myset)  total++;
      return {NULL, total};
          
}

