/*

Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.

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
int inorder(TreeNode* A,int key)
{
    if(A==NULL)
    return 0;
    TreeNode* current=A;
    stack<TreeNode*> s;
    int done=0;
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
                if(temp->val==key)
                return 1;
                current=temp->right;
            }
            else done=1;
        }
    }
    return 0;
}

TreeNode* find_lca(TreeNode* A,int val1,int val2)
{
    if(A==NULL)
    return NULL;
    if(A->val==val1 || A->val==val2)
    {
        return A;
    }
    TreeNode* left_lca=find_lca(A->left,val1,val2);
    TreeNode* right_lca=find_lca(A->right,val1,val2);
    if(left_lca!=NULL && right_lca!=NULL)
    return A;
    if(left_lca!=NULL)
    return left_lca;
    else return right_lca;
}

int Solution::lca(TreeNode* A, int val1, int val2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int x=inorder(A,val1);
    int y=inorder(A,val2);
    if(x==0 || y==0)
    return -1;
    TreeNode* lca= find_lca(A,val1,val2);
    return lca->val;
}
