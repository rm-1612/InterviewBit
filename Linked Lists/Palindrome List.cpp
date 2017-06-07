/*

Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes: 
- Expected solution is linear in time and constant in space.

For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverse(ListNode* A)
{
    ListNode* next;
    ListNode* current=A;
    ListNode* prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
int Solution::lPalin(ListNode* A) {
    
    
    ListNode* slow=A;
    ListNode* fast=A;
    ListNode* prev=NULL;
    ListNode* head1=NULL;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL )
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast==NULL)
    {
        head1=slow;
        prev->next=NULL;
    }
    else
    {
        head1=slow->next;
        slow->next=NULL;
    }
    head1=reverse(head1);
    ListNode* current=A;
    while(current!=NULL && head1!=NULL)
    {
        if(current->val!=head1->val)
        return 0;
        current=current->next;
        head1=head1->next;
    }
    return 1;
}
