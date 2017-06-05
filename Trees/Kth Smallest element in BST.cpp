/*

Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST
 
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
 
int small_element(TreeNode* root,int K)
{
    if(root==NULL)
    return 0;
    TreeNode* current=root;
    int ctr=0;
    int done=0;
    stack<TreeNode* > s;
    while(!done)
    {
        if(current!=NULL)
        {
            s.push(current);
            current=current->left;
        }
        else
        {
            if(s.empty()==false)
            {
                TreeNode* t=s.top();
                ++ctr;
                if(ctr==K)
                {
                    return t->val;
                }
                current=t->right;
                s.pop();
            }
            else done=0;
            
        }
    }
    return 0;
    
}
int Solution::kthsmallest(TreeNode* root, int k) {
    
    return small_element(root,k);
    
}
