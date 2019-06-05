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
    ListNode* oddEvenList(ListNode* head) {
    ListNode *odd_head = new ListNode(99);
    ListNode *even_head = new ListNode(22);
    ListNode *odd_temp =odd_head;
    ListNode *even_temp = even_head;
    
    int count =1;
    while(head != NULL){
        if(count % 2 == 0){
            even_temp->next = head;
            even_temp = even_temp->next;
        }else {
            odd_temp->next = head;
            odd_temp = odd_temp->next;
        }
        head = head->next;
        ++count;
    }
        
    // append odd_end and even_head
    even_temp->next = NULL;
    odd_temp->next = even_head->next;
      
    if(odd_head->next != NULL)
        return odd_head->next;
    return even_head->next;
    }
};
