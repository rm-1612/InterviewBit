/*

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* res=NULL;
    int carry=0;
    ListNode* prev=NULL;
    ListNode* temp;
    while(A!=NULL || B!=NULL)
    {
        int sum=carry+(A!=NULL?A->val:0)+(B!=NULL?B->val:0);
        carry = (sum >= 10)? 1 : 0;
        sum=sum%10;
        temp=new ListNode(sum);
        if(res==NULL)
        res=temp;
        else prev->next=temp;
        prev=temp;
        if(A!=NULL)
        {
            A=A->next;
        }
        if(B!=NULL)
        {
            B=B->next;
        }
    }
    if(carry>0)
    temp->next=new ListNode(carry);
    
    return res;
}
