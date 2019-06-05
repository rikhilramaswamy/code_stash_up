
long how_many_BSTs_helper(int num_nodes){
    
    if (num_nodes <= 1)
        return 1;
    
    long num_trees = 0;
    for(int cnt= 1; cnt <= num_nodes ; ++cnt) {
        // 1 root node; (cnt-1) nodes to left sub-tree
        long left = how_many_BSTs_helper( cnt -1);
        // remaining nodes are included part of right sub-tree
        long right = how_many_BSTs_helper(num_nodes - cnt);
        
        // left # of  ways to build left_subtree; right # of ways to build right sub-tree
        num_trees += (left * right);
    }
    
    
    return num_trees;   
}

/*
 * Complete the function below.
 */
long how_many_BSTs(int n) {
    
   return how_many_BSTs_helper(n);


}

