/*

Given a BST node, return the node which has value just greater than the given node.

Example:

Given the tree

               100
              /   \
            98    102
           /  \
         96    99
          \
           97
Given 97, you should return the node corresponding to 98 as thats the value just greater than 97 in the tree.
If there are no successor in the tree ( the value is the largest in the tree, return NULL).

Using recursion is not allowed.

Assume that the value is always present in the tree.

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
TreeNode* inorder(TreeNode* A,int B)
{
    if(A==NULL)
    return A;
    TreeNode* current=A;
    int done=0;
    stack<TreeNode*> s;
    int flag=0;
    while(!done)
    {
        if(current)
        {
            s.push(current);
            current=current->left;
        }
        else
        {
            if(!s.empty())
            {
                TreeNode* temp=s.top();
                s.pop();
                if(flag==1)
                {
                    return temp;
                }
                if(temp->val==B)
                {
                    flag=1;
                }
                current=temp->right;
            }
            else done=1;
        }
    }
    return NULL;
}
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    return inorder(A,B);
    
}
