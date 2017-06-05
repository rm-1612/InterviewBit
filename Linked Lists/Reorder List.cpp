/*

Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack<ListNode*> s;
    ListNode* slow=A;
    ListNode* fast=A;
    ListNode* head=NULL;
    ListNode* prev=NULL;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast==NULL)
    {
        head=prev->next;
        prev->next=NULL;
    }
    else
    {
        head=slow->next;
        slow->next=NULL;
    }
    ListNode* temp=head;
    while(temp!=NULL)
    {
        s.push(temp);
        temp=temp->next;
    }
    ListNode* current=A;
    while(!s.empty())
    {
        ListNode* c=s.top();
        s.pop();
        c->next=current->next;
        current->next=c;
        current=current->next->next;
    }
    return A;
    
}
