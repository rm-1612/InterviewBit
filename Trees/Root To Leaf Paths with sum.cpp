/*

Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
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
 int evaluate(vector<int> row)
 {
     int sum=0;
     for(int i=0;i<row.size();++i)
     {
         sum+=row[i];
     }
     return sum;
 }
void has_sum(TreeNode* root,int sum,vector<int> &row,vector<vector<int> > &solution)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->left==NULL && root->right==NULL)
    {
        row.push_back(root->val);
        int sum1=evaluate(row);
        if(sum1==sum)
        {
            solution.push_back(row);
        }
        row.pop_back();
        return ;
    }
    row.push_back(root->val);
    has_sum(root->left,sum,row,solution);
    has_sum(root->right,sum,row,solution);
}
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > solution;
    vector<int> row;
    has_sum(root,sum,row,solution);
    return solution;
    
}
