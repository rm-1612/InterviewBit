/*

Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

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
 TreeNode* build_tree(vector<int> &inorder, vector<int> &postorder,int instart,int inend,int &postindex)
 {
     if(instart>inend)
     return NULL;
     
     TreeNode* root=new TreeNode(postorder[postindex--]);
     if(instart==inend)
     return root;
     
     int index=search(inorder,instart,inend,root->val);
     
     root->right=build_tree(inorder,postorder,index+1,inend,postindex);
     root->left=build_tree(inorder,postorder,instart,index-1,postindex);
     return root;
 }
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n=postorder.size();
    int postindex=n-1;
    return build_tree(inorder,postorder,0,n-1,postindex);
    
}
