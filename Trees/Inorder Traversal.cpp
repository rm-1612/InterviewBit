/*

Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

Using recursion is not allowed.

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
vector<int> Solution::inorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> vec;
    if(A==NULL)
    return vec;
    
    int done=0;
    TreeNode* current=A;
    stack<TreeNode*> s;
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
                current=s.top();
                vec.push_back(current->val);
                s.pop();
                current=current->right;
            }
            else done=1;
        }
    }
    return vec;
    
}
