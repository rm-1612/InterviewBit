/*

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* func(ListNode* A)
{
    if(A==NULL)
    return A;
    ListNode* current=A;
    while(current!=NULL && current->next!=NULL)
    {
        if(current->val==current->next->val)
        {
            ListNode* temp=current->next;
            current->next=current->next->next;
            free(temp);
        }
        else current=current->next;
    }
    return A;
}
ListNode* Solution::deleteDuplicates(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    return func(A);
    
    
}
