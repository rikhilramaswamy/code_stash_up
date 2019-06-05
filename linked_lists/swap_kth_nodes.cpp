
/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/
LinkedListNode* swap_nodes(LinkedListNode* head, int k) {
    
    // n1 is nothing but first_k
    // find kth node from beginning
    LinkedListNode *prev1 = NULL;
    LinkedListNode *temp = head;
    LinkedListNode *n1 = NULL;

    while((--k)){
        prev1 = temp;
        temp= temp->next;
    }
    n1 = temp;
    //cout<<"\n prev1 is: "<<prev1->val;
    
    //cout<<"\n n1 is: "<<n1->val;
    
    // find the kth node from end 
    LinkedListNode *temp2 = head;
   LinkedListNode * prev2 = NULL;
    LinkedListNode * n2 = n1;
    
    while(n2->next != NULL){
        n2= n2->next;
        prev2= temp2;
        temp2= temp2->next;
    }
    n2 = temp2;
    
   
    //cout<<"\n prev2 is: "<<prev2->val;
    
//    cout<<"\n n2 is: "<<n2->val;

    
    // finally reassign the nodes properly
    // NOTE: the order ; you are taking care of prev-nodes first 
    if( prev1 == NULL){
        head = n2;
    } else {
        prev1->next = n2;
    }
    
    if(prev2 == NULL){
        head = n1;
    } else {
        prev2->next = n1;
    }
   
    // now take care of next nodes 
    LinkedListNode * N1_NEXT = n1->next;
    n1->next = n2->next;
    n2->next = N1_NEXT;
    
    return head;
}


