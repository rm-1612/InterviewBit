/*

Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 ListNode* sorted_merge(ListNode* A,ListNode* B)
 {
     if(A==NULL)
     return B;
     if(B==NULL)
     return A;
     ListNode* result=NULL;
     if(A->val<B->val)
     {
         result=A;
         result->next=sorted_merge(A->next,B);
     }
     else
     {
         result=B;
         result->next=sorted_merge(A,B->next);
     }
     return result;
 }
 
 void split(ListNode* A,ListNode** ptr1,ListNode** ptr2)
 {
     ListNode* slow=A;
     ListNode* fast=A;
     ListNode* prev=NULL;
     while(slow!=NULL && fast!=NULL && fast->next!=NULL)
     {
         prev=slow;
         slow=slow->next;
         fast=fast->next->next;
     }
     *ptr1=A;
     if(fast==NULL)
     {
         *ptr2=prev->next;
         prev->next=NULL;
     }
     else
     {
         *ptr2=slow->next;
         slow->next=NULL;
     }
 }
 
void merge_sort(ListNode** A)
 {
     ListNode* head=*A;
     if(head==NULL || head->next==NULL)
     return ;
     ListNode* ptr1;
     ListNode* ptr2;
     split(head,&ptr1,&ptr2);
     merge_sort(&ptr1);
     merge_sort(&ptr2);
     *A=sorted_merge(ptr1,ptr2);
 }
 
ListNode* Solution::sortList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode* head=A;
    merge_sort(&head);
    return head;
    
    
}
