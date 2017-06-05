/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric. 
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int mirror(TreeNode* A,TreeNode* B)
{
    if(A==NULL && B==NULL)
    return 2;
    if(A==NULL)
    return 0;
    if(B==NULL)
    return 0;
    if(A->val!=B->val)
    return 0;
    if(A!=NULL && B!=NULL && A->val==B->val && mirror(A->left,B->right) && mirror(A->right,B->left))
    return 1;
    return 0;
}
int Solution::isSymmetric(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return mirror(A,A);
}
