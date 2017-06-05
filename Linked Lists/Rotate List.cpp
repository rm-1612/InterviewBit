/*

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int ctr=0;
    if(A==NULL || A->next==NULL)
    return A;
    
    ListNode* current=A;
    while(current!=NULL)
    {
        ++ctr;
        current=current->next;
    }
    B=B%ctr;
    current=A;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=A;
    
    ctr=ctr-B;
    int count=0;
    current=A;
    while(count<ctr-1)
    {
        current=current->next;
        ++count;
    }
    ListNode* new_head=current->next;
    current->next=NULL;
    A=new_head;
    return A;
}
