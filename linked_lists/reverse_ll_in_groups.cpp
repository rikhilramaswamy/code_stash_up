
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

LinkedListNode* reverse_ll(LinkedListNode *head){
    if (head == NULL)
        return NULL;

    // if len(ll) = 1; return original
    if(head->next == NULL)
        return head;

    LinkedListNode* prev = NULL;
    LinkedListNode * after = NULL;
    LinkedListNode *curr = head;

    while(curr != NULL){
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;

    }
    return prev;
}

LinkedListNode* reverse_linked_list_in_groups_of_k(LinkedListNode* head, int k) {
    
    if(head == NULL)
        return NULL;
        
    LinkedListNode * t = head;
    int count =0;
    LinkedListNode *res = NULL;
    LinkedListNode *start = head;

    while(t != NULL){
        ++count;
        if( count == k || t->next == NULL){
            LinkedListNode *next_point = t->next;
            
            // NULL terminate the sub-list that should be reversed
            t->next = NULL;
            LinkedListNode *rev_res = reverse_ll(start);
            if(res == NULL){
                head = rev_res;
                
            }else {
                res->next = rev_res;
                
            }
        
            res= start;
            t = next_point;
            start = next_point;
            count =0;
        }else {
            t= t->next;
        }
    }
    
    return head;
}
