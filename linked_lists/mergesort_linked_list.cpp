/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *nmerge(ListNode * head1, ListNode *head2){
        // dummy new head
        ListNode * nhead = new ListNode(90);
        ListNode * temp = nhead;
        while(head1 != NULL && head2 != NULL){
            if(head1->val < head2->val){
                temp->next = head1;
                head1= head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        
        while(head1 != NULL){
             temp->next = head1;
             head1= head1->next;
            temp = temp->next;
        }
        
        while(head2 != NULL){
             temp->next = head2;
             head2= head2->next;
            temp = temp->next;
        }
        temp->next = NULL;
        
        return nhead->next;
    }
    
    ListNode * nmergesort(ListNode * temp){
        if(temp == NULL)
            return NULL;
        
        // length 1
        if(temp->next == NULL)
            return temp;
        
        // split into two linked lists
        ListNode * prev_slow = NULL;
        ListNode *slow = temp;
        ListNode *fast = temp;
        while(fast != NULL && fast->next != NULL){
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // null terminate first list 
        if(prev_slow != NULL)
            prev_slow->next = NULL;
        
        // now list1: temp;; list2: slow
        
        ListNode * head1 = nmergesort(temp);
        
        ListNode *head2 = nmergesort(slow);
        return nmerge(head1, head2);
        
    }
    
    ListNode* sortList(ListNode* head) {
        return nmergesort(head);
    }
};
