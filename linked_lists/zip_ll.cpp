
/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode* next;
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


LinkedListNode* zip_given_linked_list(LinkedListNode* head) {
    // find the middle node keeping track of the prev
    LinkedListNode *fast = head;
    LinkedListNode *slow = head;
    LinkedListNode *prev = NULL;
    
    // zero len ll
    if(fast == NULL){
        return NULL;
    }
    
    // single ll
    if(fast->next == NULL)
        return fast;
    
    while(fast && fast->next != NULL){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    
   // slow points to middle elem
   LinkedListNode *head2 =  reverse_ll(slow);
   
   // ll1 (head to prev)
   prev->next = NULL;
   LinkedListNode *first = head;
   LinkedListNode *res_head =head;
   LinkedListNode *temp = head;
   first = first->next;
   
   while(first != NULL && head2!= NULL ){
       temp->next = head2;
       head2 = head2->next;
       temp->next->next = NULL; 
       temp = temp->next;
       
       temp->next = first;
       first = first->next;
       temp->next->next = NULL;
       temp= temp->next;
   }
   
   while(head2!= NULL){
       temp->next = head2;
       head2= head2->next;
       temp=temp->next;
       temp->next = NULL;
   }
   
   while(first != NULL){
       temp->next = first;
       first = first->next;
       temp= temp->next;
       temp->next = NULL;
   }


    return res_head;
}


/*    optimsed */

// Reverse singly linked list in O(len) time and O(1) space. 
LinkedListNode *reverse_linked_list(LinkedListNode *cur)
{
	LinkedListNode *prev = NULL;
	LinkedListNode *next;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

LinkedListNode *zip_given_linked_list(LinkedListNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	/*
	Using slow-fast technique find the middle element.
	If head: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL,
	then slow should stop at 3.
	*/ 
	LinkedListNode *slow = head;
	LinkedListNode *fast = head->next;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	/*
	Separate linked lists from middle. 
	list1: 1 -> 2 -> 3 -> NULL
	list2: 4 -> 5 -> 6 -> NULL
	*/
	LinkedListNode *list1 = head;
	LinkedListNode *list2 = slow->next;
	/*
	Till now:
	1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
	With list1 pointing to 1, list2 pointing to 4 and slow pointing to 3.

	Now break main linked list into two parts.
	So do 3->next = NULL.
	*/
	slow->next = NULL;
	/*
	From
	list2: 4 -> 5 -> 6 -> NULL
	to 
	list2: 6 -> 5 -> 4 -> NULL
	*/
	list2 = reverse_linked_list(list2);
	/*
	Instead of defining two new pointers next1 and next2, we can use previously defined slow and 
	fast to save memory, but for readability purpose we have used two new pointers.
	*/
	LinkedListNode *next1;
	LinkedListNode *next2;
	/*
	Merge list1 and list2.
	list1: 1 -> 2 -> 3 -> NULL
	list2: 6 -> 5 -> 4 -> NULL
	merged: 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> NULL
	*/
	while (list2)
	{
		next1 = list1->next;
		next2 = list2->next;
		list1->next = list2;
		list2->next=next1;
		list1 = next1;
		list2 = next2;
	}
	return head;
}

