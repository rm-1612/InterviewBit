/*

Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]

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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > result;
    if(A==NULL)
    return result;
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(A);
    vector<int> v1;
    while(!s1.empty() || !s2.empty())
    {
        v1.clear();
        while(!s1.empty())
        {
            TreeNode* current=s1.top();
            s1.pop();
            v1.push_back(current->val);
            if(current->left!=NULL)
            s2.push(current->left);
            if(current->right!=NULL)
            {
                s2.push(current->right);
            }
        }
        if(v1.size()>0)
        result.push_back(v1);
        v1.clear();
        while(s2.empty()==false)
        {
            TreeNode* current=s2.top();
            s2.pop();
            v1.push_back(current->val);
            if(current->right!=NULL)
            s1.push(current->right);
            if(current->left!=NULL)
            {
                s1.push(current->left);
            }
        }
        if(v1.size()>0)
        result.push_back(v1);
    }
    return result;
}
