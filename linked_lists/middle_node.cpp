LinkedListNode* find_middle_node(LinkedListNode* head) {
    
    LinkedListNode * slow= head;
    LinkedListNode * fast = head;
    
    if(fast == NULL)
        return NULL;
        
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
    
}
