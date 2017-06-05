/*

Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
* If n is greater than the size of the list, remove the first node of the list. 
Try doing it using constant additional space.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* current=A;
    int ctr=0;
    while(current!=NULL && ctr<B)
    {
        current=current->next;
        ++ctr;
    }
    if(current==NULL)
    {
        ListNode* temp=A;
        A=A->next;
        free(temp);
        return A;
    }
    ListNode* ptr=A;
    while(current->next!=NULL)
    {
        ptr=ptr->next;
        current=current->next;
    }
    ListNode* temp=ptr->next;
    ptr->next=ptr->next->next;
    free(temp);
    return A;
}
