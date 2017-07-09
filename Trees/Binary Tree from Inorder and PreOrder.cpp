/*

Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3


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
 
 int search(vector<int> &inorder,int instart,int inend,int val)
 {
     for(int i=instart;i<=inend;++i)
     {
         if(inorder[i]==val)
         return i;
     }
 }
 
TreeNode* build_tree(vector<int> &preorder, vector<int> &inorder,int instart,int inend,int &preindex)
{
    if(instart>inend)
    return NULL;
    
    TreeNode* root=new TreeNode(preorder[preindex++]);
    if(instart==inend)
    return root;
    
    int index=search(inorder,instart,inend,root->val);
    
    root->left=build_tree(preorder,inorder,instart,index-1,preindex);
    root->right=build_tree(preorder,inorder,index+1,inend,preindex);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=preorder.size();
    int preindex=0;
    return build_tree(preorder,inorder,0,n-1,preindex);
    
}
