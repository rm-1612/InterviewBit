/*

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode* t=new ListNode(0);
    ListNode* p=NULL;
    t->next=A;
    p=t;
    
    while(p!=NULL && p->next!=NULL && p->next->next!=NULL)
    {
        if(p->next->val==p->next->next->val)
        {
            int dup=p->next->val;
            while(p->next!=NULL && p->next->val==dup)
            p->next=p->next->next;
        }
        else p=p->next;
    }
    
    return t->next;
    
}
