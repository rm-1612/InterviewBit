/*

Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void sorted_insert(ListNode** head_ref, ListNode* current)
 {
     
     if(*head_ref==NULL || ((*head_ref)->val)>current->val)
     {
         current->next=*head_ref;
         *head_ref=current;
     }
     else
     {
         ListNode* c=*head_ref;
         while(c->next!=NULL && c->next->val<current->val)
     {
         c=c->next;
     }
     current->next=c->next;
     c->next=current;
     }
     
     
 }
ListNode* Solution::insertionSortList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* head=NULL;
    if(A==NULL || A->next==NULL)
    return A;
    ListNode* current=A;
    while(current!=NULL)
    {
        ListNode* next=current->next;
        sorted_insert(&head,current);
        current=next;
    }
    return head;
}
