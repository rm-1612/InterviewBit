/*

Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> vec;
    if(A==NULL)
    return vec;
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(A);
    while(s1.empty()==false)
    {
        TreeNode* current=s1.top();
        s1.pop();
        s2.push(current);
        if(current->left)
        s1.push(current->left);
        if(current->right)
        s1.push(current->right);
    }
    while(s2.empty()==false)
    {
        TreeNode* c=s2.top();
        vec.push_back(c->val);
        s2.pop();
    }
    return vec;
}
