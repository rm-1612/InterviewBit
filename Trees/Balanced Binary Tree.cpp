/*

Given a binary tree, determine if it is height-balanced.

 Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 
          1
         / \
        2   3

Return : True or 1 

Input 2 : 
         3
        /
       2
      /
     1

Return : False or 0 
         Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
         Difference = 2 > 1. 
         
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
int height(TreeNode* A) 
{
    if(A==NULL)
    return 0;
    int lht=height(A->left);
    int rht=height(A->right);
    return 1+max(lht,rht);
}
int balanced(TreeNode* A)
{
    if(A==NULL)
    return 1;
    int lht=height(A->left);
    int rht=height(A->right);
    if(fabs(lht-rht)<=1 && balanced(A->left) && balanced(A->right))
    return 1;
    return 0;
}
int Solution::isBalanced(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    //( Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
    return 1;
    return balanced(A);
}
         
